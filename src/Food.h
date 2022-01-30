//
// Created by Radmilo Racic on 23/09/2021.
//

#ifndef SDL2TEST_FOOD_H
#define SDL2TEST_FOOD_H
#include "SDL.h"
#include "GameObject.h"

class Food : public GameObject {
public:
    Food(): GameObject(ObjectType::foodObject, 0xFF), _point{0, 0}, _msTimer(10000) {};
    Food(SDL_Point p, int alpha, int msTimer): GameObject(ObjectType::foodObject, alpha), _point(p), _msTimer(msTimer) {};

    // getters
    int getXCoordinate() const { return _point.x; }
    int getYCoordinate() const { return _point.y; }
    int getMsTimer() const { return _msTimer; }

    // setters
    void setXCoordinate(int x);
    void setYCoordinate(int y);
    
    void setMsTimer(std::size_t msTimer);
    void setAlpha(int a);
private:
    SDL_Point _point;
    std::size_t _msTimer;
};


#endif //SDL2TEST_FOOD_H
