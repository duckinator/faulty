#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#include <faulty/constants.h>

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

    return true;
}

void on_cleanup() {
    SDL_Quit();
}

// ===== Main loop. =====

int main(int argc, char *argv[]) {
    if(on_init() == false) {
        on_cleanup();
        return -1;
    }

    SDL_Event event;
    bool running = true;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }

            on_event(event);
        }

        on_loop();
        on_render();
    }

    on_cleanup();

    return 0;
}
