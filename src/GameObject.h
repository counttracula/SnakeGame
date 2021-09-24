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
    // ctors
    GameObject(): _type(ObjectType::noObject), _alpha(0xFF) {};
    GameObject(ObjectType ot, int a): _type(ot), _alpha(a) {};
    // dtor
    ~GameObject();

    // getter methods
    ObjectType getType() { return _type; }

    // to facilitate multi-threading
    virtual void simulate() {};

protected:
    ObjectType _type;                 // identifies the class type
    int _alpha;                       // opacity
    std::vector<std::thread> threads; // holds all threads that have been launched within this object
    static std::mutex _mtx;           // mutex shared by all game objects that protects rendering
};


#endif //SDL2TEST_GAMEOBJECT_H
