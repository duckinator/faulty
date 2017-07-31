#include <faulty.h>

void render_map(Map *map, SDL_Window *window) {
    // ASSUMPTION: map and window should not be null, because there should be
    //             checks elsewhere for this before this function is called.

    int idx = 0;
    for (uint8_t row = 0; row < TILES_PER_COL; row++) {
        for (uint8_t col = 0; col < TILES_PER_ROW; col++) {
            if (map->tiles[idx].tile_type == TILE_TYPE_NONE) {
                idx++;
                continue;
            }

            unsigned int tile_x = row * TILE_SIZE;
            unsigned int tile_y = col * TILE_SIZE;

            //????
        }
    }
}
