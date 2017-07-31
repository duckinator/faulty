#include <faulty.h>

void clear_map(Map *map) {
    memset(map, 0, sizeof(map));
}

bool load_map(Map *map, char *file) {
    Tile *tile = NULL;

    clear_map(map);

    FILE *file_handle = fopen(file, "r");

    if(file_handle == NULL) {
        return false;
    }

    uint8_t idx = 0;
    for (uint8_t col = 0; col < TILES_PER_COL; col++) {
        for (uint8_t row = 0; row < TILES_PER_ROW; row++) {
            *tile = map->tiles[idx];

            fscanf(file_handle, "%d:%d ", &(tile->tile_id), &(tile->tile_type));

            idx++;
        }
    }

    return true;
}
