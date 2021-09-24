//
// Created by Radmilo Racic on 24/09/2021.
//

#include "GameObject.h"
#include <iostream>

std::mutex GameObject::_mtx;

GameObject::~GameObject() {
    // set up thread barrier before this object is destroyed
    // objThread.join();
}

GameObject::GameObject(GameObject const &source) {
    // copy ptrs and create a new image from the source
    _type = source._type;
    _alpha = source._alpha;
    // _objThread = source._objThread;
}

GameObject::GameObject(GameObject &&source) {
    // move ptrs
    _type = source._type;
    _alpha = source._alpha;
}

GameObject& GameObject::operator=(const GameObject &source) {
    _type = source._type;
    _alpha = source._alpha;
    return *this;
}

GameObject& GameObject::operator=(GameObject &&source) {
    if (this == &source)
        return *this;

    // move ptrs
    _type = source._type;
    _alpha = source._alpha;
    return *this;
}