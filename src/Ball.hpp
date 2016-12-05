#pragma once

#include "Timer.hpp"
#include "Pad.hpp"
#include "Sprite.hpp"

class Ball : public Sprite
{
public:
    enum class Action
    {
        Attached,
        Move
    };

    Ball(SDL_Renderer *renderer, const Pad &pad);

    SDL_Rect getRect() const override;
    void updatePosition() override;
    void setAngle(int angle);

private:
    float x_;
    float y_;
    int angle_;
    float radian_;
    bool isLost_;

    Timer timer_;
    Action action_;
    const Pad &pad_;

    bool checkCollisions();
    bool checkArenaCollisions(const SDL_Rect &ball);
    bool checkPadCollision(const SDL_Rect &ball);
};
