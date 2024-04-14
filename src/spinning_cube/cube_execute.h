#include <SDL2/SDL.h>
#include "cube.h"


void execute () {
    Screen screen;

    std::vector<vec3> points {
        {50, 50, 50},
        {150, 50, 50},
        {150, 150, 50},
        {50, 150, 50},

        {50, 50, 150},
        {150, 50, 150},
        {150, 150, 150},
        {50, 150, 150}
    };

    std::vector<connection> connections {
        {0, 4},
        {1, 5},
        {2, 6},
        {3, 7},

        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0},

        {4, 5},
        {5, 6},
        {6, 7},
        {7, 4},
    };

    vec3 centroid = {0, 0, 0};
    for (auto &p : points) {
        centroid.x += p.x;
        centroid.y += p.y;
        centroid.z += p.z;
    }

    centroid.x /= points.size();
    centroid.y /= points.size();
    centroid.z /= points.size();

    while (true) {
        for (auto &p : points) {
            p.x -= centroid.x;
            p.y -= centroid.y;
            p.z -= centroid.z;
            rotate(p, 0.002, 0.001, 0.004);
            p.x += centroid.x;
            p.y += centroid.y;
            p.z += centroid.z;

            screen.pixel(p.x, p.y);
        }
    
        for (auto &c : connections) {
            line(screen, points[c.a].x, points[c.a].y, points[c.b].x, points[c.b].y);
        }
    
        screen.show();
        screen.clear();
        screen.input();
        SDL_Delay(500/60);
    }
}