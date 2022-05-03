#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../core/Window.hpp"

class TextureManager
{
public:
    TextureManager();
    ~TextureManager();

    static void load_image(char *file, Window &window, int width, int height);

private:
    static SDL_Texture *m_pTexture;
    static SDL_Surface *m_pSurface;

    static SDL_Rect m_srcRect;
    static SDL_Rect m_destRect;
};
