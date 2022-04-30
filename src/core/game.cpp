#include <iostream>

#include "game.hpp"
#include "constants.hpp"

Game::Game()
{
    /*
     * SDL initialization
     */

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }

    /*
     * SDL window initialization
     */

    m_window = SDL_CreateWindow(
        "Rougelike",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        window_flags);
    if (!m_window)
    {
        std::cout << "Failed to open window: " << SDL_GetError() << std::endl;
        exit(1);
    }

    /*
     * SDL renderer initialization
     */

    m_renderer = SDL_CreateRenderer(
        m_window,
        -1,
        renderer_flags);
    if (!m_renderer)
    {
        std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
        exit(1);
    }

    /*
     * SDL image initialization
     */

    if (IMG_Init(image_flags) == 0)
    {
        std::cout << "Failed to init image: " << IMG_GetError() << std::endl;
        exit(1);
    }

    /*
     * Image load
     */

    m_surface = IMG_Load("assets/player/idle.png");
    if (!m_surface)
    {
        std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
    }
    else
    {
        m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);
        SDL_FreeSurface(m_surface);

        SDL_QueryTexture(m_texture, nullptr, nullptr, &m_srcRect.w, &m_srcRect.h);


        m_destRect.x = m_srcRect.x = 0;
        m_destRect.y = m_srcRect.y = 0;
        m_destRect.w = m_srcRect.w = PLAYER_WIDTH;
        m_destRect.h = m_srcRect.h = PLAYER_HEIGHT;
    }

    /*
     * entt initialization
     */

    const auto player = m_registry.create();
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
    Uint32 frame = SDL_GetTicks() / 200;
    Uint32 sprite = frame % 12;

    m_srcRect.x = PLAYER_WIDTH * sprite;
}

void Game::render()
{
    SDL_SetRenderDrawColor(m_renderer, 96, 128, 255, 255);
    SDL_RenderClear(m_renderer);

    SDL_RenderCopy(m_renderer, m_texture, &m_srcRect, &m_destRect);

    SDL_RenderPresent(m_renderer);
}

void Game::clean()
{
    IMG_Quit();
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
