#pragma once

#include <SDL2/SDL.h>
#include <entt/entt.hpp>

class RenderSystem
{
public:
    RenderSystem() = default;
    ~RenderSystem() = default;

    void render(SDL_Renderer *renderer, entt::registry& registry);

};
