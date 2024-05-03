#include <vector>
#include <SDL2/SDL_rect.h>

class Rectangle {
    private:
        SDL_Rect rect;
    public:

        Rectangle(int xpos, int ypos, int width, int height) {
            rect.x = xpos;
            rect.y = ypos;
            rect.w = width;
            rect.h = height;
        }

        std::vector<int> getPosition() {
            std::vector<int> position {rect.x, rect.y};
            return position;
        }

        void updatePosition(int newxpos, int newypos) {
            rect.x = newxpos;
            rect.y = newypos;
        }

        SDL_Rect getRect() {
            return rect;
        }
};