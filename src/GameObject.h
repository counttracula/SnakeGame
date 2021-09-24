//
// Created by Radmilo Racic on 24/09/2021.
//

#ifndef SDL2TEST_GAMEOBJECT_H
#define SDL2TEST_GAMEOBJECT_H

#include <thread>
#include <mutex>
#include <vector>
#include "SDL.h"

enum ObjectType
{
    noObject,
    snakeObject,
    foodObject
};

class GameObject
{
public:
    // constructor / desctructor
    GameObject(): _point{0, 0}, _type(ObjectType::noObject) {};
    GameObject(ObjectType ot, SDL_Point p): _type(ot), _point(p) {};
    ~GameObject();

    // getter methods
    ObjectType getType() { return _type; }

    // to facilitate multi-threading
    virtual void simulate() {};

protected:
    ObjectType _type;                 // identifies the class type
    SDL_Point _point;                 // the main point of the game object.
                                      // for food is the only one, for the snake its the head
    std::vector<std::thread> threads; // holds all threads that have been launched within this object
    static std::mutex _mtx;           // mutex shared by all game objects that protects rendering
};


#endif //SDL2TEST_GAMEOBJECT_H
