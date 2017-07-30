#ifndef FAULTY_DEBUG_H
#define FAULTY_DEBUG_H

#if defined(DEBUG) && DEBUG > 0
    #define DEBUG_PRINT(fmt, ...) fprintf(stderr, "DEBUG: %s:%d:%s(): " fmt, \
                __FILE__, __LINE__, __func__, ## __VA_ARGS__)
#else
    #define DEBUG_PRINT(fmt, ...) /* Do nothing if not in release builds. */
#endif

#endif
