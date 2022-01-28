#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include <memory>

class Food;

template <typename T>
class Renderer {
 public:
  Renderer(const T screen_width, const T screen_height,
           const T grid_width, const T grid_height);
  ~Renderer();

  void Render(Snake const snake, Food const &food);
  void UpdateWindowTitle(int score, int fps, int speed, int foodOpacity);

private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const T screen_width;
  const T screen_height;
  const T grid_width;
  const T grid_height;
};

#endif