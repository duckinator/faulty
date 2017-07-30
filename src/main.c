#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    SDL_Init (SDL_INIT_VIDEO);

    SDL_Window *sdlWnd = SDL_CreateWindow ("Test", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);

    SDL_Event event;
    bool running = true;

    while (running) {
        while (SDL_PollEvent (&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
        }
    }

    return 0;
}
