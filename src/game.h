#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "Food.h"
#include "snake.h"
#include "Timer.h"
#include <memory>


class Game {
 public:
  Game();
  Game(std::size_t grid_width, std::size_t grid_height, std::size_t timer);

  void run(Controller const &controller, Renderer<std::size_t> &renderer,
           std::size_t target_frame_duration);

  void stop();

  int getScore() const;
  int getRawScore() const;
  int getSize() const;

  bool isRunning() { return !paused; }
  void pauseTheGame() { snake->pauseTheSnake(); paused = true; }
  void restartTheGame() { snake->restartTheSnake(); paused = false; }

 private:
  std::unique_ptr<Snake> snake;
  std::unique_ptr<Food> food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  std::uniform_int_distribution<int> random_a;

  Uint32 timeOfLunch;
  std::size_t inactivityTimer;

  int rawScore{0};
  int score{0};
  bool running{false};
  bool paused{false}; 
  void placeFood();
  void update();
};

#endif