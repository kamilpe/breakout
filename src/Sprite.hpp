#pragma once

#include <SDL.h>
#include <string>

class Sprite
{
public:    
    virtual SDL_Rect getRect() const = 0;
    virtual void updatePosition() = 0;
    virtual SDL_Texture *getTexture() const;
    
protected:
    SDL_Texture *texture_;
    int width_;
    int height_;

    void loadTexture(SDL_Renderer *renderer, const std::string &filename);
};
