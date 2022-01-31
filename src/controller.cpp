#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::changeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::handleInput(bool &running, bool &paused, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          changeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          changeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          changeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          changeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
        case SDLK_RETURN:
          snake.speed += 0.02;
          break;
        case SDLK_q:
          running = false;
          break;
        case SDLK_p:
          // pause the game
          snake.pauseTheSnake();
          paused = true;
          std::cout << "Game paused!" << std::endl;
          break;
        case SDLK_c:
          // restart the game
          std::cout << "Restarting the game!" << std::endl;
          snake.restartTheSnake();
          paused = false;
          break;
      }
    }
  }
}