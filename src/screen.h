#include <SDL2/SDL.h>
#include <vector>

class Screen {
    SDL_Event e;
    SDL_Window *window;
    SDL_Renderer *renderer;
    std::vector<SDL_FPoint> points;

    public:
    Screen() {
        SDL_Init(SDL_INIT_VIDEO);
        SDL_CreateWindowAndRenderer(200*2, 200*2, 0, &window, &renderer);
        SDL_RenderSetScale(renderer, 2, 2);
    }

    void pixel(float x, float y) {
        SDL_FPoint point;
        point.x = x;
        point.y = y;
        points.emplace_back(point);
    }

    void show() {
        SDL_SetRenderDrawColor(renderer, 18, 18, 40, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 100, 255, 80, 255);
        for (auto &point : points) {
            SDL_RenderDrawPointF(renderer, point.x, point.y);
        }

        SDL_RenderPresent(renderer);
    }

    void clear() {
        points.clear();
    }

    void input() {
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                SDL_Quit();
                exit(0);
            }
        }
    }
};