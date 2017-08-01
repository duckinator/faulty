#include <faulty.h>

SDL_Texture *load_texture(SDL_Renderer *renderer, uint8_t texture_id) {
    char *file_path = get_path_for_file(TILES_DIR, texture_id, ".bmp");
    SDL_Texture *texture = NULL;
    SDL_Surface *surface = SDL_LoadBMP(file_path);

    if(surface == NULL){
        // TODO: pass failure up the call stack.
        SDL_ERROR_PRINT();
        SDL_FreeSurface(surface);
        surface = NULL;
    } else {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface); /* surface is no longer needed. */
        surface = NULL; /* Reset the pointer. */
        if(texture == NULL){
            SDL_ERROR_PRINT();
        }
    }

    return texture;
}

void render_texture (SDL_Renderer *renderer, SDL_Texture *texture, int x, int y)
{
    /* dest is a structure defining a rectangle at x, y that's w pixels wide
     * and h pixels tall. */
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;

    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(renderer, texture, NULL, &dest);
}


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

            SDL_Texture *texture = load_texture(renderer, tile->tile_id);
            render_texture(renderer, texture, tile_x, tile_y);
        }
    }

    return true;
}
