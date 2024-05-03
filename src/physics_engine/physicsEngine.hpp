#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include "Rectangle.hpp"

class PhysicsEngine {

public:
    // constructor
    PhysicsEngine();
    // deconstructor
    ~PhysicsEngine();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() {
        return isRunning;
    }
private:
    int width;
    int height;
    bool isRunning;
    int lastUpdateTime = 0;
    std::vector<Rectangle> rectangles;
    SDL_Window *window;
    SDL_Renderer *renderer;
};