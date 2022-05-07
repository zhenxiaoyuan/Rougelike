#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <entt/entt.hpp>

#include "Window.hpp"
#include "../systems/RenderSystem.hpp"

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    void sdl_init();
    void entt_init();

    void events();
    void update();
    void render();
    void clean();

    Window m_window;

    bool game_is_running;

    entt::registry m_registry;

    RenderSystem m_render_system;
};