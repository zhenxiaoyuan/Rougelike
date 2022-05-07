#include "Sprite.hpp"

#include <iostream>

Sprite::Sprite(const char *file, SDL_Renderer *renderer, int width, int height)
    : m_spriteWidth{width}, m_spriteHeight{height}
{
    SDL_Surface *pSurface = IMG_Load(file);
    if (!pSurface)
    {
        std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
    }
    else
    {
        m_pTexture = SDL_CreateTextureFromSurface(renderer, pSurface);
        SDL_FreeSurface(pSurface);

        SDL_QueryTexture(m_pTexture, nullptr, nullptr, &m_textureWidth, &m_textureHeight);
    }
}

Sprite::~Sprite()
{
}

int Sprite::width()
{
    return m_spriteWidth;
}

int Sprite::height()
{
    return m_spriteHeight;
}

SDL_Texture *Sprite::texture()
{
    return m_pTexture;
}