#include <faulty.h>

Map *map = NULL;
uint8_t map_id = 0;

static SDL_Window *window = NULL;

// ===== Gameplay events. =====

void on_event(SDL_Event event) {
    printf("Event type: %i\n", event.type);
}

void on_loop() {
    // ...
}

void on_render() {
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

    // Set up map.
    map_id = 0;
    Map *map = malloc(sizeof(Map));

    if (map == NULL) {
        fprintf(stderr, "malloc(): failed to allocate memory for map.");
        return false;
    }

    return true;
}

void on_cleanup() {
    free(map);

    SDL_Quit();
}

// ===== Main loop. =====

int main(int argc, char *argv[]) {
    SDL_Event event;
    bool running = true;

    if(on_init() == false) {
        fprintf(stderr, "on_init(): failed to initialize game; exiting.");
        on_cleanup();
        return -1;
    }

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }

            on_event(event);
        }

        on_loop(map);
        on_render(map);
    }

    on_cleanup(map);

    return 0;
}
