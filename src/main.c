#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_image.h>

SDL_Window *window;
SDL_Renderer *renderer;

bool initSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Breakout", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    if (!window){
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer){
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        return false;
    }

    int flags=IMG_INIT_JPG|IMG_INIT_PNG;
    if(IMG_Init(flags) != flags)
    {
        printf("IMG_Init: Failed to init required jpg and png support\n");
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

        //Timer::updateTicks();
        //input.process(event);
        //playground.update();
        //screen.render();
    }

    closeSDL();
    return 0;
}
