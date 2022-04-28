#pragma once

#include <SDL2/SDL.h>

class Game
{
public:
    Game();
    ~Game();

    void run();

private:

    void events();
    void update();
    void render();
    void clean();

    SDL_Window *window;
    SDL_Renderer *renderer;

    const static int window_flags = SDL_WINDOW_SHOWN;
    const static int renderer_flags = SDL_RENDERER_ACCELERATED;

    bool game_is_running;
};