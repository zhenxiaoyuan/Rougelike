#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <entt/entt.hpp>

#include "Window.hpp"
#include "../systems/RenderSystem.hpp"

struct FrameTime
{
    const double delay_time = 1000.0 / 60.0;
    double last_time = 0;
    double current_time = 0;
    double time = 0;
};

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
    void render(double time);
    void clean();

    double frame();

    Window m_window;

    bool game_is_running;

    entt::registry m_registry;

    RenderSystem m_render_system;

    FrameTime m_frame_time;
};