#include <vector>
#include <SDL2/SDL_rect.h>

// + as down is taken to be positive, top is origin
const double GRAVITATIONAL_ACCELERATION = 9.8;
const double PIXELS_PER_METER = 5.0;

class Rectangle {
    private:
        SDL_Rect rect;
        double velocityY;
    public:

        Rectangle(int xpos, int ypos, int width, int height) : velocityY(0) {
            rect.x = xpos;
            rect.y = ypos;
            rect.w = width;
            rect.h = height;
        }

        // std::vector<int> getCurrentPosition(int currentTime) {
        //     std::vector<int> position {rect.x, rect.y + static_cast<int>(0.5 * GRAVITATIONAL_ACCELERATION * pow(currentTime, 2))};
        //     return position;
        // }

        std::vector<double> getVelocity(int currentTime) {
            std::vector<double> velocity {0, GRAVITATIONAL_ACCELERATION * currentTime};
            return velocity;
        }

        void updatePosition(double deltaTime) {
            // Update velocity due to gravity
            velocityY += GRAVITATIONAL_ACCELERATION * deltaTime;

            // Update position based on velocity
            rect.y += static_cast<int>(velocityY * deltaTime * PIXELS_PER_METER);
        }

        SDL_Rect getRect() {
            return rect;
        }
};