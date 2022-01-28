#include "Timer.h"
#include <iostream>

Timer::Timer(const std::chrono::milliseconds &interval, 
            const std::function<void()> &task) : _interval(interval), _task(task), _isRunning(false) {}

Timer::~Timer() {
    stop();
}

bool Timer::isRunning() const {
    return _isRunning;
}

void Timer::start() {
    _isRunning = true;
    _thread = std::thread([this] {
        while (_isRunning) {
            std::unique_lock<std::mutex> lock(_mtx);
            
            auto waitResult = _cond.wait_for(lock, _interval, [this]
                { return !_isRunning; });
            
            if (_isRunning && !waitResult) {
                _task();
            }
        }
    });
}


void Timer::stop() {
    std::unique_lock<std::mutex> lock(_mtx2);
    _isRunning = false;
    _cond.notify_all();
    if (_thread.joinable())
        _thread.join();
}