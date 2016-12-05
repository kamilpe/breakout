#include "GameScreen.hpp"

GameScreen::GameScreen(SDL_Renderer *renderer, const Pad &pad, const Ball &ball)
    : renderer_(renderer)
    , pad_(pad)
    , ball_(ball)
{
}

void GameScreen::render()
{
    const auto padRect = pad_.getRect();
    const auto ballRect = ball_.getRect();

    SDL_RenderClear(renderer_);
    SDL_RenderCopy(renderer_, pad_.getTexture(), NULL, &padRect);
    SDL_RenderCopy(renderer_, ball_.getTexture(), NULL, &ballRect);
    SDL_RenderPresent(renderer_);
}
