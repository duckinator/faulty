#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>


void handle(SDL_Event event)
{
    printf("Event type: %i\n", event.type);
}

int main(int argc, char *argv[])
{
    SDL_Init (SDL_INIT_VIDEO);

    SDL_Window *sdlWnd = SDL_CreateWindow ("Faulty", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);

    SDL_Event event;

    while(true) {
        if(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }

            handle(event);
        }
    }

    return 0;
}
