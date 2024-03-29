# Snake Game 

This is a repo for the Capstone project in the [Udacity C++ Nanodegree Program].
It is an extension of the Snake Game template provided. The following have been 
added to satisfy the project's requirements:

* Food has been abstracted out
* Food gets harder to see (decreasing opacity) with more success
* Inactivity or poor play cause a loss of points (if we do not get to eat the food on time)
  * There is a new Timer thread which notifies the game on every penalty timers' expiration
    * Default inactivity timer is 10s
* In game, the commands are:
  * q: Quit
  * ENTER: Increase game speed
  * p: Pause
  * c: Continue
* After every successful feeding, an obstacle pops up that our snake needs to avoid. Otherwise,
it will die.
  

In the end the project ought to demonstrate the use of:
* OOP, including but not limited to:
    * Inheritance
      * GameObject -> Food/Obstacle/Snake hierarchy
    * Method overloading
    * Polymorphism
      * Opacity management through the objects
    * Templates
      * Renderer class has been templated for illustrative purposes.
* Basic as well as advanced memory management concepts
  * When it comes to memory management, we've elected, for educational and illustrative purposes, to utilize the heap 
    for some objects that would otherwise be placed on the stack. Again, this was only to illustrate the command of the syntax.
    In general, objects whos size relatively small and well known at compile time can easily go on the stack whereeas objects
    whose size is unknown and potentially unlimited ought to go on the heap. One such objec is the vector of obstacles, for instance. 
* Concurrency
  * In addition to SDL libraries and the main thread, there is a timer thread that notifies (via a condition varible) the main thread, 
  where the game runs and causes penalites. 

<img src="snake_game.gif"/>

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
