#include "GameScreen.hpp"

GameScreen::GameScreen(SDL_Renderer *renderer, Playground &playground)
    : renderer_(renderer)
    , play_(playground)
{
}

void GameScreen::render()
{
    const auto padRect = play_.getPad().getRect();
    const auto ballRect = play_.getBall().getRect();

    SDL_RenderClear(renderer_);

    SDL_SetRenderDrawColor(renderer_, 20, 20, 20, 255);
    SDL_RenderFillRect(renderer_, &play_.getCoords());
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    
    SDL_RenderCopy(renderer_, play_.getPad().getTexture(), NULL, &padRect);
    SDL_RenderCopy(renderer_, play_.getBall().getTexture(), NULL, &ballRect);
    
    SDL_RenderPresent(renderer_);
}
