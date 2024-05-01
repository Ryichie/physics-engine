#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

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
    int counter = 0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};