#pragma once

#include "Timer.hpp"
#include "Sprite.hpp"

class Pad : public Sprite
{
public:
    enum class Action
    {
        None,
        GoToLeft,
        GoToRight,
        StopFromLeft,
        StopFromRight
        
    };

    Pad(SDL_Renderer *renderer, const SDL_Rect &range);
    SDL_Rect getRect() const override;
    void updatePosition() override;
    
    void setAction(Action action);
    Action getAction() const;
    
private:
    int x_;
    Action action_;
    Timer timer_;
    const SDL_Rect &range_;

    void limiter();
};
