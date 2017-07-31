#include <faulty.h>

void render_map(SDL_Renderer *renderer, Map *map) {
    // ASSUMPTION: map and window should not be null, because there should be
    //             checks elsewhere for this before this function is called.

    int idx = 0;
    for (uint8_t row = 0; row < TILES_PER_COL; row++) {
        for (uint8_t col = 0; col < TILES_PER_ROW; col++) {
            //if (map->tiles[idx].tile_type == TILE_TYPE_NONE) {
            if (true) {
                printf("meep?\n");
                printf("%i\n", map->tiles[idx].tile_type);
                printf("hi");
                idx++;
                continue;
            }

            // lol why the hell does it assume TILE_SIZE, a number literal,
            // is a signed int when nothing around it treats it as one?!
            unsigned int tile_x = row * (unsigned int)TILE_SIZE;
            unsigned int tile_y = col * (unsigned int)TILE_SIZE;

            //????
        }
    }
}
