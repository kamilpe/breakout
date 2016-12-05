#pragma once

#include <SDL.h>
#include "Playground.hpp"

class GameScreen
{
public:
    GameScreen(SDL_Renderer *renderer, Playground &playground);
    void render();

private:
    SDL_Renderer *renderer_;
    Playground &play_;
};
