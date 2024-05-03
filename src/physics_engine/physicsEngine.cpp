#include "physicsEngine.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <iostream>

const float ONE_SECOND = 1000;
const int TARGET_FPS = 60;


PhysicsEngine::PhysicsEngine() {

}

PhysicsEngine::~PhysicsEngine() {

}

void PhysicsEngine::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    this->width = width;
    this->height = height;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Initialised." << std::endl;
        window = SDL_CreateWindow("PhysicsEngine", xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "Window created." << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created." << std::endl;
        }
        isRunning = true;

        Rectangle rectangle(width / 2, -50, 10, 10);
        rectangles.push_back(rectangle);

    } else {
        isRunning = false;
    }
}

void PhysicsEngine::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void PhysicsEngine::update() {
    // Calculate time (ms) since last update
    Uint32 currentTime = SDL_GetTicks();
    double deltaTime = (currentTime - lastUpdateTime) / ONE_SECOND; // Convert milliseconds to seconds
    lastUpdateTime = currentTime;

    // Adjust deltaTime to achieve target FPS
    double targetDeltaTime = 1.0 / TARGET_FPS;
    if (deltaTime < targetDeltaTime) {
        SDL_Delay((targetDeltaTime - deltaTime) * ONE_SECOND); // Delay in milliseconds
        deltaTime = targetDeltaTime;
    }

    for (Rectangle &rectangle : rectangles) {
        rectangle.updatePosition(deltaTime);
    }
}


void PhysicsEngine::render() {
    SDL_RenderClear(renderer);

    // add things to be rendered.
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for (Rectangle &rectangle : rectangles) {
        SDL_Rect rect = rectangle.getRect();
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
        if (rect.y >= this->height) {
            isRunning = false;
        }
    }
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);

}

void PhysicsEngine::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "PhysicsEngine Cleaned" << std::endl;
}