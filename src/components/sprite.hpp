#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite
{
public:
    Sprite(const char *file, SDL_Renderer *renderer, int width, int height);

    ~Sprite();

    int width();
    int height();

    SDL_Texture *texture();

private:
    SDL_Texture *m_pTexture;

    int m_spriteWidth;
    int m_spriteHeight;

    int m_textureWidth;
    int m_textureHeight;
};