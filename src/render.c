#include <faulty.h>

bool render_map(SDL_Renderer *renderer, Map *map) {
    if (map == NULL) {
        ERROR_PRINT("map is null.\n");
        return false;
    }
    // ASSUMPTION: map and window should not be null, because there should be
    //             checks elsewhere for this before this function is called.

    uint32_t idx = 0;
    printf("???\n");
    printf("%p\n", map->tiles);
    printf("!!!\n");
    Tile *tile = map->tiles;
    for (uint8_t row = 0; row < TILES_PER_COL; row++) {
        for (uint8_t col = 0; col < TILES_PER_ROW; col++) {
            //if (map->tiles[idx].tile_type == TILE_TYPE_NONE) {
            if (true) {
                printf("<idx %u>\n", idx);
                //Tile *tile = &map->tiles[0];
                //uint8_t x = map->tiles[0].tile_type;
                printf("???\n");
                printf("%u\n", tile->tile_type);
                printf("</idx>\n");
                tile++;
                continue;
            }

            // lol why the hell does it assume TILE_SIZE, a number literal,
            // is a signed int when nothing around it treats it as one?!
            uint32_t tile_x = row * (uint32_t)TILE_SIZE;
            uint32_t tile_y = col * (uint32_t)TILE_SIZE;

            //????
        }
    }
}
