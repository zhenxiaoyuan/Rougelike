#include <iostream>

#include "Game.hpp"
#include "../utils/Constants.hpp"

#include "../components/Sprite.hpp"
#include "../components/Position.hpp"

#include "../managers/TextureManager.hpp"

Game::Game()
    : m_window {}
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }

    m_window.create();

    if (IMG_Init(image_flags) == 0)
    {
        std::cout << "Failed to init image: " << IMG_GetError() << std::endl;
        exit(1);
    }

    const auto player = m_registry.create();

    m_registry.emplace<Sprite>(player, PLAYER_WIDTH, PLAYER_HEIGHT);
    m_registry.emplace<Position>(player, 100, 100);


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

}

void Game::render()
{
    SDL_SetRenderDrawColor(m_window.renderer(), 96, 128, 255, 255);
    SDL_RenderClear(m_window.renderer());

    m_render_system.render(m_window.renderer(), m_registry);

    SDL_RenderPresent(m_window.renderer());
}

void Game::clean()
{
    IMG_Quit();
    SDL_Quit();
}
