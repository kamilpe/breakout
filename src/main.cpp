#include "Playground.hpp"
#include "GameInput.hpp"
#include "GameScreen.hpp"
#include "Timer.hpp"

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

namespace
{
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
}

bool initSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Breakout", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr){
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return false;
    }

    int flags=IMG_INIT_JPG|IMG_INIT_PNG;
    if(IMG_Init(flags) != flags)
    {
        std::cout << "IMG_Init: Failed to init required jpg and png support";
    }
    return true;
}

void closeSDL()
{
    if (renderer)
        SDL_DestroyRenderer(renderer);
    if (window)
        SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char **argv)
{
    initSDL();

    Playground playground{renderer, SDL_Rect{50, 50, 600, 500}};
    GameScreen screen{renderer, playground};
    GameInput input{playground.getPad()};

    SDL_Event event;
    bool quit = false;
    while (!quit)
    {
        // Get input

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
            {
                quit = true;
                break;
            }
            }
        }

        Timer::updateTicks();
        input.process(event);
        playground.update();
        screen.render();
    }

    closeSDL();
    return 0;
}
