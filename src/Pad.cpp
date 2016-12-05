#include "Pad.hpp"

namespace
{
    const auto START_SPEED = Timer::Miliseconds(15);
    const auto ACCELERATION = Timer::Miliseconds(1);
    const auto FINAL_SPEED = Timer::Miliseconds(3);
}

Pad::Pad(SDL_Renderer *renderer)
    : x_(200)
    , action_(Action::None)
{
    loadTexture(renderer, "pad.png");
}

SDL_Rect Pad::getRect() const
{
    return
    {
        x_ - (width_ / 2),
        500 - height_ - 10,
        width_,
        height_
    };
}

Pad::Action Pad::getAction() const
{
    return action_;
}

void Pad::setAction(Action action)
{
    if (action_ == action)
        return;
    action_ = action;

    switch (action_)
    {
    case Action::None:
        timer_.stop();
        break;

    case Action::GoToLeft:
    case Action::GoToRight:
        timer_.start(START_SPEED);
        break;

    case Action::StopFromLeft:
    case Action::StopFromRight:
        // timer already started
        break;
    }
}

void Pad::updatePosition()
{
    if (action_ == Action::None)
        return;

    switch (action_)
    {
    case Action::None: break;
    case Action::GoToLeft:
    {
        while (timer_.pop())
        {
            x_ -= 1;
            if (timer_.getFrequency() > FINAL_SPEED)
                timer_.setFrequency(timer_.getFrequency() - ACCELERATION);
        }
        break;
    }
    case Action::GoToRight:
    {
        while (timer_.pop())
        {
            x_ += 1;
            if (timer_.getFrequency() > FINAL_SPEED)
                timer_.setFrequency(timer_.getFrequency() - ACCELERATION);
        }
        break;
    }
    case Action::StopFromLeft:
    {
        while (timer_.pop())
        {
            x_ -= 1;
            if (timer_.getFrequency() < START_SPEED)
                timer_.setFrequency(timer_.getFrequency() + ACCELERATION);
            else
                setAction(Action::None);
        }        
        break;
    }
    case Action::StopFromRight:
    {
        while (timer_.pop())
        {
            x_ += 1;
            if (timer_.getFrequency() < START_SPEED)
                timer_.setFrequency(timer_.getFrequency() + ACCELERATION);
            else
                setAction(Action::None);
        }        
        break;
    }
    }
}
