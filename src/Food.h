//
// Created by Radmilo Racic on 23/09/2021.
//

#ifndef SDL2TEST_FOOD_H
#define SDL2TEST_FOOD_H
#include "SDL.h"

class Food {
public:
    Food(): _point{0, 0}, _alpha(0xF0) {};
    Food(SDL_Point p, int alpha): _point(p), _alpha(alpha) {};

    SDL_Point getCoordinates() const { return _point; }
    int getAlpha() const { return _alpha; }

    void setCoordinates(SDL_Point p);
    void setAlpha(int a);

    SDL_Point _point;
    int _alpha;
};


#endif //SDL2TEST_FOOD_H
