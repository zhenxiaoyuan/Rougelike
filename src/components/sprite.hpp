#pragma once

#include <SDL2/SDL.h>

#include "../core/Window.hpp"

class Sprite
{
public:
    Sprite(int width, int height);
    Sprite();

    Sprite(Sprite&&);
    Sprite& operator=(Sprite&&);

    ~Sprite() = default;

    SDL_Texture     *m_pTexture;

    SDL_Rect         m_srcRect;
    SDL_Rect         m_destRect;

private:
    SDL_Renderer     *m_pRenderer;
    SDL_Surface      *m_pSurface;

    Window          m_window;

    char            *m_pFile;
    int              m_width;
    int              m_height;
};