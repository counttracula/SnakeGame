#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller {
 public:
    
    void handleInput(bool &running, bool &paused, Snake &snake) const;

 private:
    void changeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif