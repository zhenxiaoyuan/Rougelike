#include "Sprite.hpp"
#include "../core/Window.hpp"

#include <SDL2/SDL_image.h>
#include <iostream>

Sprite::Sprite()
{
    
}

Sprite::Sprite(int width, int height)
    : m_width {width}, m_height {height}
{
    m_pSurface = IMG_Load("");
    if (!m_pSurface)
    {
        std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
    }
    else
    {
        m_pTexture = SDL_CreateTextureFromSurface(Window::m_pRenderer, m_pSurface);
        SDL_FreeSurface(m_pSurface);

        SDL_QueryTexture(m_pTexture, nullptr, nullptr, &m_srcRect.w, &m_srcRect.h);

        m_destRect.x = m_srcRect.x = 0;
        m_destRect.y = m_srcRect.y = 0;
        m_destRect.w = m_srcRect.w = width;
        m_destRect.h = m_srcRect.h = height;
    }
}

Sprite::Sprite(Sprite&& s)
{
    this->m_srcRect = s.m_srcRect;
    this->m_destRect = s.m_destRect;
}

Sprite& Sprite::operator=(Sprite&& s)
{
    if (this != &s)
    {
        this->m_srcRect = s.m_srcRect;
        this->m_destRect = s.m_destRect;
    }

    return *this;
}