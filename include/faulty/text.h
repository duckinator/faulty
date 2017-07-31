#ifndef FAULTY_TEXT_H
#define FAULTY_TEXT_H

#if defined(DEBUG) && DEBUG > 0
    #define DEBUG_PRINTF(fmt, ...) fprintf(stderr, "DEBUG: %s:%d:%s(): " fmt, \
                __FILE__, __LINE__, __func__, ## __VA_ARGS__)
#else
    #define DEBUG_PRINTF(fmt, ...) /* Do nothing if not in release builds. */
#endif

#define DEBUG_PRINT(str) DEBUG_PRINTF("%s", str)

#define ERROR_PRINTF(fmt, ...) fprintf(stderr, "ERROR: %s:%d:%s(): " fmt, \
                __FILE__, __LINE__, __func__, ## __VA_ARGS__)

#define ERROR_PRINT(str) DEBUG_PRINTF("%s", str)

#endif
