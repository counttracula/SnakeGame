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

  std::unique_ptr<Renderer<std::size_t>> renderer(new Renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight)); // initialize on the heap for illustration purposes
  Controller controller; // controller can stay on the stack, no member vars

  std::unique_ptr<Game> gamePtr(new Game(kGridWidth, kGridHeight, kTimer)); 
  gamePtr->run(std::move(controller), *renderer, kMsPerFrame); // move the controller to the Game object's scope
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << gamePtr->getScore() << "\n";
  std::cout << "Final snake size: " << gamePtr->getSize() << "\n";
  return 0;
}