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

    int getXCoordinate() const { return _point.x; }
    int getYCoordinate() const { return _point.y; }
    int getAlpha() const { return _alpha; }

    void setXCoordinate(int x);
    void setYCoordinate(int y);
    void setAlpha(int a);

private:
    SDL_Point _point;
    int _alpha;
};


#endif //SDL2TEST_FOOD_H
