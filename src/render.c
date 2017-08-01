#include <faulty.h>

bool render_map(SDL_Renderer *renderer, Map *map) {
    if (map == NULL) {
        ERROR_PRINT("map is null.\n");
        return false;
    }

    if (renderer == NULL) {
        ERROR_PRINT("renderer is null.\n");
        return false;
    }

    Tile *tile = NULL;
    uint32_t idx = 0;
    for (uint8_t row = 0; row < TILES_PER_COL; row++) {
        for (uint8_t col = 0; col < TILES_PER_ROW; col++) {
            tile = &map->tiles[idx];

            if (tile->tile_type == TILE_TYPE_NONE) {
                idx++;
                continue;
            }

            // lol why the hell does it assume TILE_SIZE, a number literal,
            // is a signed int when nothing around it treats it as one?!
            uint32_t tile_x = row * (uint32_t)TILE_SIZE;
            uint32_t tile_y = col * (uint32_t)TILE_SIZE;

            //????
        }
    }

    return true;
}
