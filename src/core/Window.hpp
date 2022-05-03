#pragma once

#include <SDL2/SDL.h>

class Window
{
public:
    Window();
    ~Window();

    Window(Window &&);
    Window(Window &);

    Window& operator=(Window&&);

    static void create();
    static SDL_Renderer *renderer();

    static SDL_Renderer *m_pRenderer;
    static SDL_Window   *m_pWindow;
private:

    const static int window_flags   = SDL_WINDOW_SHOWN;
    const static int renderer_flags = SDL_RENDERER_ACCELERATED;
};