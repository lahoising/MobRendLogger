#ifndef _MR_LOGGER_H_
#define _MR_LOGGER_H_

#ifdef __cplusplus
#include <cstdlib>
extern "C"
{
#else
#include <stdarg.h>
#endif

#define MR_LOG_BIT_UNKNOWN    0
#define MR_LOG_BIT_INFO       1
#define MR_LOG_BIT_WARN       2
#define MR_LOG_BIT_ERR        4
#define MR_LOG_BIT_ALL        MR_LOG_BIT_INFO | MR_LOG_BIT_WARN | MR_LOG_BIT_ERR

#define MR_LOG_ACTION_UNKNOWN 0
#define MR_LOG_ACTION_ON      1
#define MR_LOG_ACTION_OFF     2
#define MR_LOG_ACTION_SET     3

typedef char MobRendLogBitMask;

#ifndef NDEBUG
#define mrlog(...)  _mr_log(__FILE__,__LINE__,"","",MR_LOG_BIT_INFO,__VA_ARGS__)
#define mrerr(...)  _mr_log(__FILE__, __LINE__, "\033[1;31m", "\033[0m",MR_LOG_BIT_ERR,__VA_ARGS__)
#define mrwarn(...) _mr_log(__FILE__, __LINE__, "\033[1;33m", "\033[0m",MR_LOG_BIT_WARN,__VA_ARGS__)
#else
#define mrlog(...)
#define mrerr(...)
#define mrwarn(...)
#endif

void _mr_log(const char *f, int l, const char *colorStart, const char *colorEnd,char priority,const char *msg,...);
void mr_log_filter_output(MobRendLogBitMask mask, char logAction);

#define BAKA_ASSERT(expr)\
if((expr))\
{\
\
}\
else\
{\
    bakaerr("%s returned false",#expr);\
    abort();\
}

#ifdef __cplusplus
}
#endif

#endif