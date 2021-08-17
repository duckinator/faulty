#ifndef FAULTY_TILE_H
#define FAULTY_TILE_H

#include <stdint.h>

enum {
    TILE_TYPE_NONE = 0,

    TILE_TYPE_NORMAL,
    TILE_TYPE_BLOCK,
    TILE_TYPE_ITEM
};

typedef struct tile_s {
    uint8_t tile_id;
    uint8_t tile_type;
} Tile;

#endif
