#include "Bounce.hpp"

Bounce::Bounce(int angle)
    : angle_(angle)
{
}

int Bounce::hitToLeft()
{
    return RIGHT_ANGLE + (LEFT_ANGLE - angle_);
}

int Bounce::hitToRight()
{
    return LEFT_ANGLE - (RIGHT_ANGLE + angle_);    
}

int Bounce::hitToTop()
{
    return BOTTOM_ANGLE + (TOP_ANGLE - angle_);
}

int Bounce::hitToBottom()
{
    return TOP_ANGLE - (BOTTOM_ANGLE + angle_);
}

int Bounce::hitToPad(const SDL_Rect &ball, const SDL_Rect &pad)
{
    int point = (ball.x + ball.w/2) - pad.x;
    if (point < 0) point = 0;
    else if (point > pad.w) point = pad.w;
    
    return 190 + (160 * point) / pad.w;
}
