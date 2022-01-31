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
    foodObject,
    obstacleObject
};

class GameObject
{
public:
    // ctors
    GameObject(): _type(ObjectType::noObject), _alpha(0xFF) {};
    GameObject(ObjectType ot, int a): _type(ot), _alpha(a) {};
    GameObject(GameObject const &source); // copy ctor
    GameObject(GameObject &&source); // move ctor

    GameObject& operator=(const GameObject &source); // copy assignment op
    GameObject& operator=(GameObject &&source); // move assignment op

    // dtor
    ~GameObject();

    // getter methods
    int getAlpha() const { return _alpha; }
    void virtual setAlpha(int a) { _alpha = a; }
    ObjectType virtual getType() { return _type; }

protected:
    ObjectType _type;                 // identifies the class type
    int _alpha;                       // opacity
    static std::mutex _mtx;           // mutex shared by all game objects that protects rendering
};


#endif //SDL2TEST_GAMEOBJECT_H
