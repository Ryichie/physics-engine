#include "physicsEngine.hpp"

PhysicsEngine *physicsEngine = nullptr;

inline void execute() {
    physicsEngine = new PhysicsEngine();

    physicsEngine->init("Physics Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 727, 727, false);

    while (physicsEngine->running()) {
        physicsEngine->handleEvents();
        physicsEngine->update();
        physicsEngine->render();
    }

    physicsEngine->clean();
}
