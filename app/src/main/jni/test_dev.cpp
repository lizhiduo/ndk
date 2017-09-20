//
// Created by lizd on 2017/9/20.
//
#include "com_example_lizd_ndk_jniUtils.h"
#include "myLog.h"

#include <unistd.h>
#include <stdio.h>

#include <string.h>

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

#include "termios.h"

#define READLENGTH  512

//#define


#define UART_DEV "/dev/ttyUSB0"
int fd = 0;

char g_uart_dev[20];
#if 0
int set_dev_mode(int fd, speed_t speed, int dataWidth, int nStop, unsigned char waitTime, int isWait)
{
    struct termios new_cfg,old_cfg;

    //preserve the old configuration
    if(tcgetattr(fd,&old_cfg)!=0){
        LOGE("tcgetattr() failed");
        return -1;
    }

    //set mode
    new_cfg.c_cflag |= CLOCAL |CREAD;

    new_cfg.c_lflag &=~ICANON; //原始模式

    //new_cfg.c_lflag |=ICANON;

    //set baudrate
    cfsetispeed(&new_cfg,speed);
    cfsetospeed(&new_cfg,speed);

    //set size of data
    new_cfg.c_cflag &=~CSIZE;
    switch(dataWidth){
        case 5:{
            new_cfg.c_cflag |= CS5;
        }break;
        case 6:{
            new_cfg.c_cflag |= CS6;
        }break;
        case 7:{
            new_cfg.c_cflag |= CS7;
        }break;
        case 8:{
            new_cfg.c_cflag |= CS8;
        }break;
        default :{
            new_cfg.c_cflag |= CS8;
        }break;
    }

    //set stopbit
    if(nStop==2)
        new_cfg.c_cflag |=(CSTOPB);
    else if(nStop==1)
        new_cfg.c_cflag &=~(CSTOPB);

    //set wait time
    if(isWait){
         new_cfg.c_cc[VTIME]= 0; //100 * 100ms
         new_cfg.c_cc[VMIN] = 0;
         //new_cfg.c_cc[VMIN] = 1;
    }else{
        new_cfg.c_cc[VTIME]= waitTime;  //n*100ms
        //new_cfg.c_cc[VTIME]= 0;
        new_cfg.c_cc[VMIN] = 0;
    }


    //start
    if(tcsetattr(fd, TCSANOW, &new_cfg) != 0){
        LOGE("tcsetattr() failed");
        return -1;
    }

    return 0;
}
#endif

int set_dev_mode(int fd, speed_t speed, int dataWidth, int nStop, unsigned char waitTime, int isWait)
{
    struct termios new_cfg,old_cfg;

    //preserve the old configuration
    if(tcgetattr(fd,&old_cfg)!=0){
        LOGE("tcgetattr() failed");
        return -1;
    }

    //set mode
    //old_cfg.c_cflag |= CLOCAL |CREAD;

    //old_cfg.c_lflag &=~ICANON; //原始模式

    //new_cfg.c_lflag |=ICANON;

    //set baudrate
    cfsetispeed(&old_cfg,speed);
    cfsetospeed(&old_cfg,speed);

    //set size of data
    old_cfg.c_cflag &=~CSIZE;

    old_cfg.c_cflag |= CS8;


    //set stopbit
    if(nStop==2)
        old_cfg.c_cflag |=(CSTOPB);
    else if(nStop==1)
        old_cfg.c_cflag &=~(CSTOPB);

#if 0
    //set wait time
    if(isWait){
         new_cfg.c_cc[VTIME]= 0; //100 * 100ms
         new_cfg.c_cc[VMIN] = 0;
         //new_cfg.c_cc[VMIN] = 1;
    }else{
        new_cfg.c_cc[VTIME]= waitTime;  //n*100ms
        //new_cfg.c_cc[VTIME]= 0;
        new_cfg.c_cc[VMIN] = 0;
    }
#endif


    //start
    if(tcsetattr(fd, TCSANOW, &old_cfg) != 0){
        LOGE("tcsetattr() failed");
        return -1;
    }

    return 0;
}

int test_cmd(){

    char buff[READLENGTH] = {'\0'};
    int nread = 0, wr_num = 0;

    char cmd[]={0x7e, 0x00, 0x07, 0x01, 0x00, 0xf0, 0x0f, 0xab, 0xcd};


	wr_num = write(fd, cmd, sizeof(cmd));
	if( wr_num != sizeof(cmd) ){
		LOGE("write cmd failed ...");
		return -1;
	}


    if( (nread = read(fd, buff, READLENGTH) ) >0 ){

        buff[nread+1] = '\0';

        #if 1

        LOGI("len: %d  flag: %x  str: %s", nread, buff[2], &buff[4]);

        #endif
    }else{
        LOGE("read fail");
    }

	return 0;
}


#if 0
JNIEXPORT void JNICALL Java_com_example_lizd_ndk_jniUtils_test
  (JNIEnv *env, jclass obj){

    speed_t SPEED = B115200;
    int ret = 0;

    fd = open(UART_DEV, O_RDWR | O_NOCTTY);
    	if(fd < 0){
            LOGE("can not open %s\n", UART_DEV);
            return ;
        }

        ret = set_dev_mode(fd, SPEED, 8, 1, 5, 0);
        	if(ret<0){
                    LOGE("set_dev_mode fail...");
                    close(fd);
                    return ;
                 }

         test_cmd();

        close(fd);


  }
#endif




#if 1
JNIEXPORT void JNICALL Java_com_example_lizd_ndk_jniUtils_test
  (JNIEnv *, jclass){

    LOGE("%s is runing...", __func__);

    char PathName[20] = "/dev/ttyUSB";
    char buff[READLENGTH] = {'\0'};
    int nread = 0, wr_num = 0, i;
    int ret = 0;
    int fd;
    unsigned char cmd[]={0x7e, 0x00, 0x07, 0x01, 0x00, 0xf0, 0x0f, 0xab, 0xcd};

    char uart_dev[20];
    speed_t SPEED = B115200;

    for (int i=0; i<3; i++){
        memset(uart_dev, 0, 20);
        sprintf(uart_dev, "%s%d", PathName, i);

        LOGI("name: %s", uart_dev);

        if((access(uart_dev, F_OK))== -1)
        {
            LOGE("%s is not exit...", uart_dev);
            continue;
        }

        fd = open(uart_dev, O_RDWR ); //  O_NONBLOCK  O_NOCTTY
        if(fd < 0){
            LOGE("OPEN %s FAILED ...", uart_dev);
            continue ;
        }
        //ret = set_dev_mode(fd, SPEED, 8, 1, 5, false);
        if(ret<0){
            LOGE("set_dev_mode fail...");
            close(fd);
            continue;
         }
         #if 1
        LOGE("Write  ...");

        wr_num = write(fd, cmd, sizeof(cmd));
        if( wr_num != sizeof(cmd) ){
            LOGE("Write CMD failed ...");
            close(fd);
            continue ;
        }
        #endif

        if( (nread = read(fd, buff, READLENGTH) ) >0 ){

            buff[nread+1] = '\0';
            #if 1
            LOGI("len: %d  flag: %x  str: %s", nread, buff[2], &buff[4]);
            #endif
            if( memcmp(&buff[4], "SD-MG1S02", 5) == 0){
                memcpy(g_uart_dev, uart_dev, strlen(uart_dev));
            }
            close(fd);
        }else{
            LOGE("READ FAILED...");
            close(fd);
            continue ;
        }
    }



  }
#endif