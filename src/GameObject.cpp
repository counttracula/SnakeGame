//
// Created by Radmilo Racic on 24/09/2021.
//

#include "GameObject.h"

std::mutex GameObject::_mtx;

GameObject::~GameObject() {
    // set up thread barrier before this object is destroyed
    for (auto &t: threads) {
        t.join();
    }
}
