#include "GameInput.hpp"

GameInput::GameInput(Pad &pad)
    : pad_(pad)
{
}

void GameInput::process(const SDL_Event &event)
{
    switch (event.type)
    {
    case SDL_KEYDOWN:
        keyDown(event.key);
        break;
    case SDL_KEYUP:
        keyUp(event.key);
        break;        
    }
}

void GameInput::keyDown(const SDL_KeyboardEvent &keyEvent)
{
    switch (keyEvent.keysym.sym)
    {
    case SDLK_LEFT:
        pad_.setAction(Pad::Action::GoToLeft);
        break;
    case SDLK_RIGHT:
        pad_.setAction(Pad::Action::GoToRight);
        break;
    }
}

void GameInput::keyUp(const SDL_KeyboardEvent &keyEvent)
{
    switch (keyEvent.keysym.sym)
    {
    case SDLK_LEFT:
        if (pad_.getAction() == Pad::Action::GoToLeft)
            pad_.setAction(Pad::Action::StopFromLeft);
        break;
    case SDLK_RIGHT:                    
        if (pad_.getAction() == Pad::Action::GoToRight)
            pad_.setAction(Pad::Action::StopFromRight);
        break;
    }
}
