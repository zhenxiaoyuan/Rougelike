#include <iostream>

#include "game.hpp"
#include "constants.hpp"

Game::Game()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }

    window = SDL_CreateWindow(
        "Rougelike",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        window_flags);
    if (!window)
    {
        std::cout << "Failed to open window: " << SDL_GetError() << std::endl;
        exit(1);
    }

    renderer = SDL_CreateRenderer(
        window,
        -1,
        renderer_flags);
    if (!renderer)
    {
        std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

Game::~Game()
{
    SDL_Quit();
}

void Game::run()
{
    game_is_running = true;

    while (game_is_running)
    {
        events();

        update();

        render();
    }

    clean();
}

void Game::events()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            game_is_running = false;
            break;
        
        default:
            break;
        }
    }
    
}

void Game::update()
{
    // TODO
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}
