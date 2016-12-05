#include "Pad.hpp"
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

    window = SDL_CreateWindow("Hello World!", 100, 100, 400, 500, SDL_WINDOW_SHOWN);
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

    Pad pad{renderer};
    Ball ball{renderer, pad};
    GameInput input{pad};
    GameScreen screen{renderer, pad, ball};

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
        pad.updatePosition();
        ball.updatePosition();        
        screen.render();
    }

    closeSDL();
    return 0;
}
