#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <functional>
#include <atomic>
#include <thread>
#include <condition_variable>

class Timer
{

public:
    Timer():_interval(10000) {};
    Timer(const std::chrono::milliseconds &interval,
          const std::function<void()> &task);
    ~Timer();

    void start();
    void stop();
    bool isRunning() const;

private:
    std::chrono::milliseconds _interval;
    std::thread _thread;
    std::function<void()> _task;
    bool _isRunning;
    std::condition_variable _cond;
    std::mutex _mtx;
    std::mutex _mtx2;
};

#endif // TIMER_H