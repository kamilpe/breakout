#include "Sprite.hpp"
#include <SDL_image.h>
#include <stdexcept>

void Sprite::loadTexture(SDL_Renderer *renderer, const std::string &filename)
{
    SDL_Surface *image = IMG_Load(filename.c_str());
    if (!image)
    {
        throw std::runtime_error("No " + filename + " found!");
    }

    texture_ = SDL_CreateTextureFromSurface(renderer, image);
    if (!texture_)
    {
        throw std::runtime_error("Unable to create texture");
    }

    width_ = image->w;
    height_ = image->h;
    SDL_FreeSurface(image);
}

SDL_Texture *Sprite::getTexture() const
{
    return texture_;
}
