#include <jni.h>
#include <stdlib.h>
#include <stdio.h>
#include <android/log.h>
#include <dlfcn.h>

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_example_hello_jni_JniClient
 * Method:    add
 * Signature: ()V
 */

#define _ATWE_JNI_
    
 char* get_MY_KEY();
 char* get_COMM_KEY();
 char* get_VERIFY_KEY();
 char* get_IMEIKEY();
 char* get_SECRETDATA();
 char* get_AAID();


#ifdef __cplusplus
}
#endif
//#endif
