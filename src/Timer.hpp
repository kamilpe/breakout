#pragma once

#include <chrono>

class Timer
{
public:    
    using Miliseconds = std::chrono::milliseconds;

    Timer();

    static void updateTicks();

    void start(Miliseconds frequency);
    void stop();
    bool isStarted() const;
    void setFrequency(Miliseconds frequency);
    Miliseconds getFrequency() const;
    bool pop();

private:
    static Miliseconds globalTime_;
    Miliseconds frequency_;
    Miliseconds lastUpdate_;
};
