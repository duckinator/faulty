#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>


void handle(SDL_Window *window, SDL_Event event)
{
    printf("Event type: %i\n", event.type);
}

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);

    SDL_Window *window =
        SDL_CreateWindow("Faulty", SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);

    SDL_Event event;

    while(true) {
        if(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }

            handle(window, event);
        }
    }

    SDL_Quit();

    return 0;
}
