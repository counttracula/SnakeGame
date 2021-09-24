//
// Created by Radmilo Racic on 23/09/2021.
//

#ifndef SDL2TEST_FOOD_H
#define SDL2TEST_FOOD_H
#include "SDL.h"
#include "GameObject.h"

class Food : public GameObject {
public:
    Food(): GameObject(), _alpha(0xF0) {};
    Food(SDL_Point p, int alpha): GameObject(ObjectType::foodObject, p), _alpha(alpha) {};

    // getters
    int getXCoordinate() const { return _point.x; }
    int getYCoordinate() const { return _point.y; }
    int getAlpha() const { return _alpha; }

    // setters
    void setXCoordinate(int x);
    void setYCoordinate(int y);
    void setAlpha(int a);
private:
    int _alpha;
};


#endif //SDL2TEST_FOOD_H
