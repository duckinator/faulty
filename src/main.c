#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

static SDL_Window *window;

void on_event(SDL_Event event) {
    printf("Event type: %i\n", event.type);
}

void on_loop() {
    // ...
}

void on_render() {
    // ...
}

// ===== Boilerplate-y things. =====

void init() {
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);

    window = SDL_CreateWindow("Faulty", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
}

void cleanup() {
    SDL_Quit();
}

int main(int argc, char *argv[]) {
    init();

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

    cleanup();

    return 0;
}
