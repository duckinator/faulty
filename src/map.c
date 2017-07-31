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
    // ASSUMPTION: map_id length is 3 characters max, because it's a uint8_t.
    //             If map_id's type is changed, that value changes, too.
    size_t file_name_max_length = strlen(MAP_DIR) + 3 /* map_id length */ + 4 /* .txt */;
    char *file_path = malloc(file_name_max_length);
    memset(file_path, 0, file_name_max_length);
    snprintf(file_path, file_name_max_length, "%s%hhu.txt", MAP_DIR, map_id);

    Tile *tile = NULL;

    printf("wat\n");
    if (clear_map(map) == false) {
        return false;
    }
    printf("fuck you\n");

    FILE *file_handle = fopen(file_path, "r");

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
//tile->tile_id = 3; tile->tile_type = 4;
printf("lol?\n");
printf("%hhu:%hhu\n", tile->tile_id, tile->tile_type);
printf("meep\n");
            // TODO: Check if there are enough rows/columns in the map file.
            fscanf(file_handle, "%hhu:%hhu ", &tile->tile_id, &tile->tile_type);
printf("idx=%u, %u:%u\n", idx, tile->tile_id, tile->tile_type);
            idx++;
        }
    }

    return true;
}
