#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <entt/entt.hpp>

#include "../systems/RenderSystem.hpp"
#include "Window.hpp"

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

    Window           m_window;

    SDL_Texture     *m_texture;
    SDL_Surface     *m_surface;
    SDL_Rect         m_srcRect;
    SDL_Rect         m_destRect;

    const static int image_flags    = IMG_INIT_PNG;

    bool game_is_running;

    entt::registry m_registry;

    RenderSystem m_render_system;
};