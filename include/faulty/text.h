#ifndef FAULTY_TEXT_H
#define FAULTY_TEXT_H

extern bool in_debug_mode;

#define DEBUG_PRINTF(fmt, ...) if (in_debug_mode == true) { fprintf(stderr, "DEBUG: %s:%d:%s(): " fmt, \
            __FILE__, __LINE__, __func__, ## __VA_ARGS__); }

#define DEBUG_PRINT(str) DEBUG_PRINTF("%s", str)

#define ERROR_PRINTF(fmt, ...) fprintf(stderr, "ERROR: %s:%d:%s(): " fmt, \
                __FILE__, __LINE__, __func__, ## __VA_ARGS__)

#define ERROR_PRINT(str) ERROR_PRINTF("%s", str)

#define SDL_ERROR_PRINT() ERROR_PRINTF("%s", SDL_GetError())

#endif
