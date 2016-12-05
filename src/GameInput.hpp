#pragma once

#include <SDL.h>
#include "Pad.hpp"

class GameInput
{
public:
    GameInput(Pad &pad);
    void process(const SDL_Event &event);
    void keyUp(const SDL_KeyboardEvent &keyEvent);
    void keyDown(const SDL_KeyboardEvent &keyEvent);

private:
    Pad &pad_;
};
