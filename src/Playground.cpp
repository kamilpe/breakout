#include "Playground.hpp"

Playground::Playground(SDL_Renderer *renderer, const SDL_Rect &rect)
    : renderer_(renderer)
    , rect_(rect)
    , pad_(renderer, rect)
    , ball_(renderer, pad_, rect)
{
}

void Playground::update()
{
    pad_.updatePosition();
    ball_.updatePosition();
}

Pad &Playground::getPad()
{
    return pad_;
}

Ball &Playground::getBall()
{
    return ball_;
}

const SDL_Rect &Playground::getCoords()
{
    return rect_;
}
