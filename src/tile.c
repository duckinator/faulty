#include <faulty.h>

Tile *create_tile(uint8_t id, uint8_t type) {
    Tile *tile = malloc(sizeof(Tile));

    tile->id = id;
    tile->type = type;

    return tile;
}
