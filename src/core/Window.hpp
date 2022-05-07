#pragma once

#include <SDL2/SDL.h>

class Window
{
public:
    Window();
    ~Window();

    void create(
        const char *title,
        int pos_x,
        int pos_y,
        int width,
        int height,
        Uint32 window_flags,
        Uint32 renderer_flags);

    SDL_Renderer *renderer();

private:
    SDL_Renderer *m_pRenderer;
    SDL_Window *m_pWindow;

};