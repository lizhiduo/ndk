LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_LDLIBS := -llog

LOCAL_SRC_FILES := test_dev.cpp
LOCAL_MODULE := test_dev

include $(BUILD_SHARED_LIBRARY)
