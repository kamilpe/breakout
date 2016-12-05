#pragma once

#include "Pad.hpp"
#include "Ball.hpp"

#include <SDL.h>

class Playground
{
public:
    Playground(SDL_Renderer *renderer, const SDL_Rect &rect);
    void update();

    const SDL_Rect &getCoords();
    Pad &getPad();
    Ball &getBall();
    
private:
    SDL_Renderer *renderer_;
    const SDL_Rect rect_;
    Pad pad_;
    Ball ball_;
};
    
