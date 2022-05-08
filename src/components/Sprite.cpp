#include "Sprite.hpp"

#include <iostream>

Sprite::Sprite(const char *file, SDL_Renderer *renderer, int width, int height, int fps)
    : m_width{width}, m_height{height}
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

        SDL_QueryTexture(m_pTexture, nullptr, nullptr, &m_texture.width, &m_texture.height);
        m_texture.fps = fps;
    }
}

Sprite::~Sprite()
{
}

int Sprite::width()
{
    return m_width;
}

int Sprite::height()
{
    return m_height;
}

SDL_Texture *Sprite::sdl_texture()
{
    return m_pTexture;
}

Texture Sprite::texture()
{
    return m_texture;
}

void Sprite::next_frame(double time)
{
    double frame_time = 1000.0 / m_texture.fps;

    accumulator += time;
    if (accumulator > frame_time)
    {
        m_texture.x = (m_texture.x + 1) % (m_texture.width / m_width);
        m_texture.y = (m_texture.y + 1) % (m_texture.height / m_height);
        accumulator -= frame_time;

    }
}