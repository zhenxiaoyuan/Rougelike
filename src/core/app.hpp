#pragma once

#include <SDL2/SDL.h>

class App
{
public:
    App();
    ~App();

    void run();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    const static int windowFlags = SDL_WINDOW_SHOWN;
    const static int rendererFlags = SDL_RENDERER_ACCELERATED;
};