#include <faulty.h>

void clear_map(Map *map) {
    memset(map, 0, sizeof(Map));
}

bool load_map(Map *map, uint8_t map_id) {
    // ASSUMPTION: map_id length is 3 characters max, because it's a uint8_t.
    //             If map_id's type is changed, that value changes, too.
    size_t file_name_max_length = strlen(MAP_DIR) + 3 /* map_id length */ + 4 /* .txt */;
    char *file_path = malloc(file_name_max_length);
    memset(file_path, 0, file_name_max_length);
    snprintf(file_path, file_name_max_length, "%s%hhu.txt", MAP_DIR, map_id);

    Tile *tile = NULL;

    clear_map(map);

    FILE *file_handle = fopen(file_path, "r");

    if(file_handle == NULL) {
        return false;
    }

    uint8_t idx = 0;
    for (uint8_t col = 0; col < TILES_PER_COL; col++) {
        for (uint8_t row = 0; row < TILES_PER_ROW; row++) {
            tile = &map->tiles[idx];

            fscanf(file_handle, "%hhu:%hhu ", &(tile->tile_id), &(tile->tile_type));

            idx++;
        }
    }

    return true;
}
