//
// Created by Visin on 3/29/2020.
//
#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_voestest_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement stringFromJNI()
    std::string hello = "Hello Visin Call from c++";
    return env->NewStringUTF((hello.c_str()));
}