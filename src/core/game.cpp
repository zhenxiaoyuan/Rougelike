#include <iostream>

#include "Game.hpp"

#include "../utils/Constants.hpp"

#include "../components/Sprite.hpp"
#include "../components/Position.hpp"

Game::Game()
{
    sdl_init();

    entt_init();
}

Game::~Game()
{
    SDL_Quit();
}

void Game::sdl_init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }

    m_window.create(
        "Rougelike",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN,
        SDL_RENDERER_ACCELERATED);

    if (IMG_Init(IMG_INIT_PNG) == 0)
    {
        std::cout << "Failed to init image: " << IMG_GetError() << std::endl;
        exit(1);
    }
}

void Game::run()
{
    game_is_running = true;
    double time;

    while (game_is_running)
    {
        events();

        time = frame();
        if (time > 0)
        {
            update();
            render(time);
        }
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

void Game::render(double time)
{
    SDL_SetRenderDrawColor(m_window.renderer(), 96, 128, 255, 255);
    SDL_RenderClear(m_window.renderer());

    m_render_system.render(m_window.renderer(), m_registry, time);

    SDL_RenderPresent(m_window.renderer());
}

void Game::clean()
{
    IMG_Quit();
    SDL_Quit();
}

void Game::entt_init()
{
    const auto player = m_registry.create();

    m_registry.emplace<Sprite>(player, "assets/player/idle.png", m_window.renderer(), PLAYER_WIDTH, PLAYER_HEIGHT, 6);
    m_registry.emplace<Position>(player, 100, 100);
}

double Game::frame()
{
    m_frame_time.current_time = SDL_GetTicks();
    if (m_frame_time.current_time > m_frame_time.last_time + m_frame_time.delay_time)
    {
        m_frame_time.time = m_frame_time.current_time - m_frame_time.last_time;
        m_frame_time.last_time = m_frame_time.current_time;

        return m_frame_time.time;
    }
    else
    {
        return 0;
    }
}