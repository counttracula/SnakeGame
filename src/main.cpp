#include <iostream>
#include "controller.h"
#include "game.h"
#include <memory>

#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  constexpr std::size_t kTimer{10}; // penalty timer in seconds

  Renderer<std::size_t> renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;

  std::unique_ptr<Game> gamePtr(new Game(kGridWidth, kGridHeight, kTimer));
  gamePtr->Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << gamePtr->GetScore() << "\n";
  std::cout << "Size: " << gamePtr->GetSize() << "\n";
  return 0;
}