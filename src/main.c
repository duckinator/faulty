#include <faulty.h>

static SDL_Window *window = NULL;

// ===== Gameplay events. =====

void on_event(Map *map, SDL_Event event) {
    printf("Event type: %i\n", event.type);
}

void on_loop(Map *map) {
    // ...
}

void on_render(Map *map) {
    // ...
}


// ===== Non-gameplay events. =====

bool on_init() {
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0) {
        return false;
    }

    window = SDL_CreateWindow("Faulty", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    if (window == NULL) {
        return false;
    }

    return true;
}

void on_cleanup(Map *map) {
    free(map);

    SDL_Quit();
}

// ===== Main loop. =====

int main(int argc, char *argv[]) {
    SDL_Event event;
    bool running = true;

    Map *map = malloc(sizeof(map));

    if (map == NULL) {
        fprintf(stderr, "malloc(): failed to allocate memory for map.");
        on_cleanup(map);
        return -1;
    }

    if(on_init() == false) {
        on_cleanup(map);
        return -1;
    }

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }

            on_event(map, event);
        }

        on_loop(map);
        on_render(map);
    }

    on_cleanup(map);

    return 0;
}
