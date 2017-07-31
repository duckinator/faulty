#include <faulty.h>

Tile *create_tile(uint8_t id, uint8_t type) {
    Tile *tile = malloc(sizeof(Tile));

    tile->tile_id = id;
    tile->tile_type = type;

    return tile;
}
