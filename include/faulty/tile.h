#ifndef FAULT_TILE_H
#define FAULTY_TILE_H

enum {
    TILE_TYPE_NONE = 0,

    TILE_TYPE_NORMAL,
    TILE_TYPE_BLOCK,
    TILE_TYPE_ITEM
};

typedef struct tile_s {
    int id;
    int type;
} Tile;

#endif
