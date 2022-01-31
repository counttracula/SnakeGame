#ifndef SDL2TEST_OBSTACLE_H
#define SDL2TEST_OBSTACLE_H
#include "SDL.h"
#include "GameObject.h"

class Obstacle : public GameObject
{
public:
    Obstacle() : GameObject(ObjectType::obstacleObject, 0xFF), _point{0, 0} {};
    Obstacle(SDL_Point p, int alpha) : GameObject(ObjectType::foodObject, alpha), _point(p) {};

    // getters
    int getXCoordinate() const { return _point.x; }
    int getYCoordinate() const { return _point.y; }

    // setters
    void setXCoordinate(int x);
    void setYCoordinate(int y);
    void setAlpha(int a);

private:
    SDL_Point _point;
};

#endif // SDL2TEST_OBSTACLE_H
