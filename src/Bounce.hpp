#pragma once

#include <SDL.h>

class Bounce
{
private:
    const int RIGHT_ANGLE = 360;
    const int LEFT_ANGLE = 180;
    const int TOP_ANGLE = 270;
    const int BOTTOM_ANGLE = 90;
    
public:
    Bounce(int angle);

    int hitToLeft();
    int hitToRight();
    int hitToTop();
    int hitToBottom();
    int hitToPad(const SDL_Rect &ball, const SDL_Rect &pad);

private:
    int angle_;
};
