#pragma once

#include <SDL.h>
#include "Pad.hpp"
#include "Ball.hpp"

class GameScreen
{
public:
    GameScreen(SDL_Renderer *renderer, const Pad &pad, const Ball &ball);
    void render();

private:
    SDL_Renderer *renderer_;
    const Pad &pad_;
    const Ball &ball_;
};
