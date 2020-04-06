#include <jni.h>
#include <string>
#include <android/log.h>

#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,"testff",__VA_ARGS__);

extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
}


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_vcpp_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    hello += avcodec_configuration();

    //初始化解封装
    av_register_all();
    //初始化网络
    avformat_network_init();
    //打开文件

    av_log_set_level(AV_LOG_DEBUG);

    AVFormatContext* ic = NULL;
    char path[] = "/sdcard/1080p.mp4";
    int re = avformat_open_input(&ic,path,0,0);

    LOGW("avformat_open_input %s !",path);
    LOGW("avformat_open_input : %s",av_err2str(re));

    if(re!=0)
    {
        return env->NewStringUTF(hello.c_str());
    }

    re = avformat_find_stream_info(ic,0);

    if(re!=0)
    {
        LOGW("avformat_find_stream_info failed!");
    }

    LOGW("duration time = %lld nb_stream = %d",ic->duration,ic->nb_streams);

    avformat_close_input(&ic);

    return env->NewStringUTF(hello.c_str());


}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_example_vcpp_MainActivity_Open(JNIEnv *env, jobject thiz, jstring url, jobject handle) {
    // TODO: implement Open()
    const char* f_url = env->GetStringUTFChars(url,0);
    FILE* fp = fopen(f_url,"rb");

    if(!fp)
    {
        LOGW("%s open filed!",f_url);
    } else{
        LOGW("%s open sucess!",f_url);
        fclose(fp);
    }

    env->ReleaseStringUTFChars(url,f_url);
    return true;
}