#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

#define DEBUG           0
#define DEBUG_SIMPLE    1

#if defined(DEBUG) && DEBUG > 0

#if DEBUG_SIMPLE
#define debug_printf(fmt, args...) printf(fmt, ##args)
#else
#define debug_printf(fmt, args...) fprintf(stderr, "DEBUG: %s:%d:%s(): " fmt, \
    __FILE__, __LINE__, __func__, ##args)
#endif

#else
 #define debug_printf(fmt, args...) 
#endif

#endif // DEBUG