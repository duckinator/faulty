#include <faulty.h>

Tile *create_tile(int id, int type) {
    Tile *tile = malloc(sizeof(Tile));

    tile->id = id;
    tile->type = type;

    return tile;
}
