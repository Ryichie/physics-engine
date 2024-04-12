#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main(int argc, char *argv[]) {

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("Physics Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_ALWAYS_ON_TOP);

    if (window == NULL) {
        cout << "Could not create SDL window: " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_RenderClear(renderer);

    SDL_Rect rect;
    rect.x = 250;
    rect.y = 150;
    rect.w = 200;
    rect.h = 200;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderPresent(renderer);

    SDL_Event windowEvent;

    while (true) {
        if (SDL_PollEvent(&windowEvent)) {
            if (SDL_QUIT == windowEvent.type) {
                break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}