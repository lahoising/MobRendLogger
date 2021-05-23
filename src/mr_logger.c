#include <stdio.h>
#include "mr_logger.h"

#ifdef _cplusplus
#include <cstring>
extern "C"
{
#else
#include <string.h>
#endif

#if defined(_WIN32)
#define MR_FILE_SEPARATOR '\\'
#endif

typedef struct
{
    MobRendLogBitMask msgMask;
} MobRendLogger;

static MobRendLogger g_mr_logger = { MR_LOG_BIT_ALL };

const char *logger_get_filename(const char *filename);

void _mr_log(const char *f, int l, const char *colorStart, const char *colorEnd,char priority,const char *msg,...)
{
    va_list va;

    if( !(g_mr_logger.msgMask & priority) ) return;
    
    va_start(va, msg);
    printf("%s%s(%d):%s ", colorStart, logger_get_filename(f), l, colorEnd);
    vprintf(msg, va);
    printf("\n");
    va_end(va);
}

const char *logger_get_filename(const char *filename)
{
    const char *sepPos = strrchr(filename, MR_FILE_SEPARATOR);

    return sepPos? sepPos + 1 : filename;
}

void mr_log_filter_output(MobRendLogBitMask mask, char logAction)
{
    switch (logAction)
    {
    case MR_LOG_ACTION_ON:
        g_mr_logger.msgMask |= mask;
        break;

    case MR_LOG_ACTION_OFF:
        g_mr_logger.msgMask &= ~mask;
        break;
    
    case MR_LOG_ACTION_SET:
        g_mr_logger.msgMask = mask;
        break;

    default:
        break;
    }
}


#ifdef _cplusplus
}
#endif