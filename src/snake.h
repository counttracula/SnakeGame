#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"
#include "GameObject.h"
#include "Obstacle.h"

class Snake : public GameObject {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height, std::vector<std::unique_ptr<Obstacle>> &o)
      : GameObject(ObjectType::snakeObject, 0xFF),
        grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2),
        obstacles(o) {}

  void update();
  void growBody();
  bool snakeCell(int x, int y);
  void pauseTheSnake() { running = false; }
  void restartTheSnake() { running = true; }
  bool isRunning() { return running; }
  Direction direction = Direction::kUp;
  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;
  std::vector<std::unique_ptr<Obstacle>> &obstacles;

 private:
  void updateHead();
  void updateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
  bool running{true};
};

#endif