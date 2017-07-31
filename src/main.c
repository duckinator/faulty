#include <faulty.h>

bool in_debug_mode = false;

Map *map = NULL;
uint8_t map_id = 0;

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

// ===== Gameplay events. =====

void on_event(SDL_Event event) {
    DEBUG_PRINTF("Event type: %i\n", event.type);
}

void on_loop() {
    // ...
}

void on_render() {
    render_map(renderer, map);
}


// ===== Non-gameplay events. =====

bool on_init() {
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0) {
        return false;
    }

    window = SDL_CreateWindow("Faulty", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    if (window == NULL) {
        ERROR_PRINT("window is null.\n");
        return false;
    }

    // Set up map.
    map_id = 0;
    Map *map = malloc(sizeof(Map));

    if (map == NULL) {
        ERROR_PRINT("Failed to allocate memory for map.\n");
        return false;
    }

    load_map(map, 0);

    return true;
}

void on_cleanup() {
    SDL_DestroyWindow(window);

    free(map);
    SDL_Quit();
}

// ===== Main loop. =====

int main(int argc, char *argv[]) {
    SDL_Event event;
    bool running = true;

    if (argc > 0) {
        for (int idx = 0; idx < argc; idx++) {
            if(strncmp(argv[idx], "--debug", 7) == 0) {
                in_debug_mode = true;
            }
        }
    }

    if(on_init() == false) {
        ERROR_PRINT("Failed to initialize game.\n");
        on_cleanup();
        return -1;
    }

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                DEBUG_PRINT("Received SDL_QUIT.");
                running = false;
                break;
            }

            on_event(event);
        }

        on_loop(map);
        on_render(map);

        SDL_Delay(200); // Avoid 100% CPU usage.
    }

    on_cleanup();

    return 0;
}
