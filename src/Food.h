//
// Created by Radmilo Racic on 23/09/2021.
//

#ifndef SDL2TEST_FOOD_H
#define SDL2TEST_FOOD_H
#include "SDL.h"
#include "GameObject.h"

class Food : public GameObject {
public:
    Food(): GameObject(), _point{0, 0} {};
    Food(SDL_Point p, int alpha): GameObject(ObjectType::foodObject, alpha), _point(p) {};

    // getters
    int getXCoordinate() const { return _point.x; }
    int getYCoordinate() const { return _point.y; }
    int getAlpha() const { return _alpha; }

    // setters
    void setXCoordinate(int x);
    void setYCoordinate(int y);
    void setAlpha(int a);
private:
    SDL_Point _point;
};


#endif //SDL2TEST_FOOD_H
