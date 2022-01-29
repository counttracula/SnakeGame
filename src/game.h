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
  Game(Game const &source); // copy ctor
  Game(Game &&source);     // move ctor

  Game &operator=(const Game &source); // copy assignment op
  Game &operator=(Game &&source);      // move assignment op

  // dtor
  // ~Game();

  void Run(Controller const &controller, Renderer<std::size_t> &renderer,
           std::size_t target_frame_duration);

  void Stop();

  int GetScore() const;
  int GetSize() const;

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

  int score{0};
  bool running{false};
  void PlaceFood();
  void Update();
};

#endif