#include "game.h"
#include <iostream>
#include "SDL.h"
#include "Timer.h"
#include <chrono>

Game::Game(std::size_t grid_width, std::size_t grid_height, std::size_t timer)
    : engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      random_a(1, 0xFF),
      timeOfLunch(0),
      inactivityTimer(timer) {
  snake.emplace_back(new Snake(grid_width, grid_height, obstacles));
  food = std::unique_ptr<Food>(new Food());
  placeGameObject(ObjectType::foodObject);
}

void Game::run(Controller const &controller, Renderer<std::size_t> &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  running = true;
  paused = false;
  std::shared_ptr<Timer> msTimer;

  frame_start = SDL_GetTicks();
  timeOfLunch = SDL_GetTicks();

  auto updateScore = [&paused=paused, &score = score, &frame_start = frame_start, &timeOfLunch = timeOfLunch, inactivityTimer=inactivityTimer]() mutable
  {
    if (frame_start - timeOfLunch > inactivityTimer*1000) {
      if (!paused && score > 0) {
            score--;
          std::cout << "Inactivity penalty! Score reduced from " << score+1 << " to " << score << std::endl;
      } else {
        frame_start = SDL_GetTicks();
      }
    }
  }; // simple lambda

  msTimer = std::make_shared<Timer>(std::chrono::seconds(inactivityTimer), updateScore);
  msTimer->start(); // spawn a timer thread to reduce the score every 10s

  while (running && snake.at(0)->alive) {
    frame_start = SDL_GetTicks();
    // launch a thread that modifies the Vehicle name

    // Input, Update, Render - the main game loop
    controller.handleInput(running, paused, *snake.at(0));
    update();
    renderer.render(*snake.at(0), *food, obstacles);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {

      renderer.updateWindowTitle(score, static_cast<int>(snake.at(0)->speed * 100));
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
  msTimer->stop();
  running = false;
  renderer.showPopUp("Game Over!", "Please try again");
}

void Game::stop() { running = false; }

void Game::placeGameObject(ObjectType gameObject) {
  int x;
  int y;
  
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    
    if (gameObject == ObjectType::foodObject) {
      // place food
      if (!snake.at(0)->snakeCell(x, y)) {
          food->setXCoordinate(x);
          food->setYCoordinate(y);
          return;
      }
    } else if (gameObject == ObjectType::obstacleObject) {
      // place obstacle
      // Check that the location is not occupied by a snake item before placing the obstacle
      if (!snake.at(0)->snakeCell(x, y)) {
        Obstacle *newObstacle = new Obstacle();
        newObstacle->setXCoordinate(x);
        newObstacle->setYCoordinate(y);
        obstacles.emplace_back(newObstacle);
        return;
      }
    }
  }
}

void Game::update() {
  if (!snake.at(0)->alive) return;

  snake.at(0)->update();

  int new_x = static_cast<int>(snake.at(0)->head_x);
  int new_y = static_cast<int>(snake.at(0)->head_y);

  // Check if there's food over here
  if (food->getXCoordinate() == new_x && food->getYCoordinate() == new_y) {
    rawScore++;
    score += rawScore * static_cast<int>(snake.at(0)->speed * 10);
    timeOfLunch = SDL_GetTicks(); // get time of lunch
    placeGameObject(ObjectType::foodObject);
    placeGameObject(ObjectType::obstacleObject);
    // Grow snake and increase speed.
    snake.at(0)->growBody();
    snake.at(0)->speed += 0.02;
    // make the food harder to find
    food->setAlpha(food->getAlpha() > 50 ? food->getAlpha() - 5 : food->getAlpha());
  }
}

int Game::getScore() const { return score; }
int Game::getRawScore() const { return rawScore; }
int Game::getSize() const { return snake.at(0)->size; }