package com.example.lizd.ndk;

/**
 * Created by lizd on 2017/9/20.
 */

public class jniUtils {
    static {
        System.loadLibrary("test_dev");
    }

    public static native void test();

}
