#include <faulty.h>

bool clear_map(Map *map) {
    if (map == NULL) {
        ERROR_PRINT("map is null");
        return false;
    }

    for (uint32_t idx = 0; idx < TILES_PER_MAP; idx++) {
        map->tiles[idx].tile_id = -1;
        map->tiles[idx].tile_type = -1;
    }

    return true;
}

Map *new_map() {
    Map *map = malloc(sizeof(Map));
    map->tiles = malloc(sizeof(Tile) * TILES_PER_MAP);

    clear_map(map);

    return map;
}

bool load_map(Map *map, uint8_t map_id) {
    char *file_path = get_path_for_file(MAP_DIR, map_id, ".txt");

    Tile *tile = NULL;

    if (clear_map(map) == false) {
        return false;
    }

    FILE *file_handle = fopen(file_path, "r");

    free(file_path);

    if(file_handle == NULL) {
        return false;
    }

    uint32_t idx = 0;
    for (uint8_t col = 0; col < TILES_PER_COL; col++) {
        for (uint8_t row = 0; row < TILES_PER_ROW; row++) {
            if (idx > (sizeof(Tile) * TILES_PER_COL * TILES_PER_ROW)) {
                ERROR_PRINTF("Trying to load too many tiles in from map #%u", map_id);
                return false;
            }

            tile = &map->tiles[idx];

            // TODO: Check if there are enough rows/columns in the map file.
            fscanf(file_handle, "%hhu:%hhu ", &tile->tile_id, &tile->tile_type);
            DEBUG_PRINTF("idx=%u, %u:%u\n", idx, tile->tile_id, tile->tile_type);

            idx++;
        }
    }

    return true;
}
