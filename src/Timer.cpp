#include "Timer.hpp"
#include <SDL.h>

namespace
{
    const auto TIMER_STOPPED = Timer::Miliseconds(0);
}

Timer::Miliseconds Timer::globalTime_{0};

Timer::Timer()
    : frequency_(TIMER_STOPPED)
{}

void Timer::start(Miliseconds frequency)
{
    updateTicks();
    frequency_ = frequency;
    lastUpdate_ = globalTime_;
}

void Timer::stop()
{
    frequency_ = TIMER_STOPPED;
}

bool Timer::isStarted() const
{
    return (frequency_ != TIMER_STOPPED);
}

void Timer::updateTicks()
{
    globalTime_ = Miliseconds(SDL_GetTicks());
}

void Timer::setFrequency(Miliseconds frequency)
{
    frequency_ = frequency;
}

Timer::Miliseconds Timer::getFrequency() const
{
    return frequency_;
}

bool Timer::pop()
{
    if (!isStarted())
        return false;
        
    if (globalTime_ - lastUpdate_ > frequency_)
    {
        lastUpdate_ += frequency_;
        return true;
    }
    return false;
}
