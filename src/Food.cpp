//
// Created by Radmilo Racic on 23/09/2021.
//

#include "Food.h"

class Food::Food {
public:

    SDL_Point getCoordinates() const { return this->_point; }
    int getAlpha() const { return this->_alpha; }

    void setCoordinates(SDL_Point p) {
        this->_point = p;
    }
    void setAlpha(int a) {
        this->_alpha = a;
    }
};
