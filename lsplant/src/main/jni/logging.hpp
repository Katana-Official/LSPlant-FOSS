#pragma once

#include <android/log.h>

#ifndef LOG_TAG
#define LOG_TAG "LSPlant"
#endif

#ifdef LOG_DISABLED
#define LOGD(...) 0
#define LOGV(...) 0
#define LOGI(...) 0
#define LOGW(...) 0
#define LOGE(...) 0
#define PLOGE(...) 0
#else
#ifndef NDEBUG
#define LOGD(fmt, ...)                                                                             \
    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG,                                                \
                        "%s:%d"                                                                    \
                        ": " fmt,                                                                  \
                        __FILE_NAME__, __LINE__ __VA_OPT__(, ) __VA_ARGS__)
#define LOGV(fmt, ...)                                                                             \
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG,                                              \
                        "%s:%d"                                                                    \
                        ": " fmt,                                                                  \
                        __FILE_NAME__, __LINE__ __VA_OPT__(, ) __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#else
#define LOGD(...) 0
#define LOGV(...) 0
#define LOGW(...) 0
#define LOGI(...) 0
#endif
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL, LOG_TAG, __VA_ARGS__)
#define PLOGE(fmt, args...) LOGE(fmt " failed with %d: %s", ##args, errno, strerror(errno))
#endif
