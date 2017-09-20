//
// Created by lizd on 2017/8/30.
// 96*96

#include <stdio.h>

#include <sys/time.h>

#include <stdlib.h>

#include "STA3Alg.h"

#include "out1.h"

void test_process(){
	
	UINT8 version[512]={'\0'};
	INT32 len=0;
	
	SY_GetSYAlgVersion(version);
  	//len=SY_GetFeatureSize();
	
	printf("version : %s \n len: %d\n", version, len);
}

int main(void){
	
	struct  timeval  start;
  struct  timeval  end;
  unsigned long timer;
  int i=0, j=0;
  
	
	char *pbuf;
	char *pFeature;
	int bin1_len = sizeof(boot_bin1);
	
	unsigned long sum=0;
	
	INT32 FeatureSize = SY_GetFeatureSize();
	
	
	pbuf = (char *)malloc(bin1_len);
	pFeature = (char *)malloc(FeatureSize);
	
//	memset(pbuf, 0, bin1_len);
//	memcpy(pbuf, boot_bin1, bin1_len);
	
	for (i=0; i<10; i++){
		
		memset(pbuf, 0, bin1_len);
		memset(pFeature, 0, FeatureSize);
	memcpy(pbuf, boot_bin1, bin1_len);
		
		gettimeofday(&start,NULL);
  
  //test_process();
	SY_GetA3Feature(pbuf, 96, 96,  pFeature);
	
  gettimeofday(&end,NULL);
  
  timer = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
  
  printf("timer = %ld us\n",timer);
  
	
		sum += timer;
	}
	
	printf("mean = %ld us\n", sum/10);
	
	for(j=20; j>0; j--){
		if(j%8==0){printf("\n");}
	  printf("0x%02x ", pFeature[FeatureSize-j]);
	}
	printf("\n");
	
	free(pbuf);
	free(pFeature);

	return 0;
}
