#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main() {
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0) {
        cout << "SDL_Init failed with error:" << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

    string hi = "hi";
    cout << hi << endl;

    SDL_Quit();

    return EXIT_SUCCESS;
}