#include "TextureManager.hpp"


#include <iostream>


TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

void TextureManager::load_image(char *file, Window &window, int width, int height)
{
    m_pSurface = IMG_Load(file);
    if (!m_pSurface)
    {
        std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
    }
    else
    {
        m_pTexture = SDL_CreateTextureFromSurface(window.renderer(), m_pSurface);
        SDL_FreeSurface(m_pSurface);

        SDL_QueryTexture(m_pTexture, nullptr, nullptr, &m_srcRect.w, &m_srcRect.h);

        m_destRect.x = m_srcRect.x = 0;
        m_destRect.y = m_srcRect.y = 0;
        m_destRect.w = m_srcRect.w = width;
        m_destRect.h = m_srcRect.h = height;
    }
}