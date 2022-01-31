#include "renderer.h"
#include <iostream>
#include <string>
#include "Food.h"
#include "Menu.h"

template <typename T>
Renderer<T>::Renderer(const T screen_width,
                   const T screen_height,
                   const T grid_width,
                   const T grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

template <typename T>
Renderer<T>::~Renderer()
{
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

template <typename T>
void Renderer<T>::Render(Snake const snake, Food const &food, std::vector<std::unique_ptr<Obstacle>> &obstacles)
{
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;
  SDL_Texture *mTexture;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, food.getAlpha());
  SDL_RenderClear(sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, food.getAlpha());
  SDL_SetRenderDrawBlendMode(sdl_renderer, SDL_BLENDMODE_BLEND);
  block.x = food.getXCoordinate() * block.w;
  block.y = food.getYCoordinate() * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  for (auto &o: obstacles) {
    // Render Obstacles
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x0C, 0x00, o->getAlpha());
    SDL_SetRenderDrawBlendMode(sdl_renderer, SDL_BLENDMODE_BLEND);
    block.x = o->getXCoordinate() * block.w;
    block.y = o->getYCoordinate() * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer, 0xA0, 0xA0, 0xA0, 0xA0);
  for (SDL_Point const &point : snake.body) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;
  if (snake.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

template <class T>
void Renderer<T>::UpdateWindowTitle(int score, int speed) {
  std::string title{"q: QUIT, enter: SPEED UP, p: PAUSE, c: CONTINUE\t\tScore: " + std::to_string(score) + ", " + "Speed: " 
                    + std::to_string(speed)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

template class Renderer<std::size_t>;