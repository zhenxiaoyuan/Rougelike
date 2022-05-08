#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct Texture
{
    int x;
    int y;
    int width;
    int height;
    int fps;
};

class Sprite
{
public:
    Sprite(const char *file, SDL_Renderer *renderer, int width, int height, int fps);

    ~Sprite();

    int width();
    int height();

    SDL_Texture *sdl_texture();
    Texture texture();

    void next_frame(double time);

private:
    SDL_Texture *m_pTexture;

    int m_width;
    int m_height;

    Texture m_texture;

    double accumulator;
};
