#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include <memory>
#include "Menu.h"

class Food;

template <typename T>
class Renderer {
 public:
  Renderer(const T screen_width, const T screen_height,
           const T grid_width, const T grid_height);
  ~Renderer();

  void Render(Snake const snake, Food const &food);
  void UpdateWindowTitle(int score, int speed);

private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  // SDL_Window and SDL_Renderer are incomplete types and usage of unique_ptr with these 
  // really complicates code. I've left these are raw pointers in the code!

  const T screen_width;
  const T screen_height;
  const T grid_width;
  const T grid_height;
};

#endif