#include <iostream>

#include "app.hpp"
#include "constants.hpp"

App::App()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

App::~App()
{
    SDL_Quit();
}

void App::run()
{
    window = SDL_CreateWindow(
        "Rougelike",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        windowFlags);
    if (!window)
    {
        std::cout << "Failed to open window: " << SDL_GetError() << std::endl;
        exit(1);
    }

    renderer = SDL_CreateRenderer(
        window,
        -1,
        rendererFlags);
    if (!renderer)
    {
        std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
        exit(1);
    }

    while (1)
    {
        SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
}
