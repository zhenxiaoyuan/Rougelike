#include "RenderSystem.hpp"

#include <iostream>

#include "../components/Sprite.hpp"
#include "../components/Position.hpp"

void RenderSystem::render(SDL_Renderer *renderer, entt::registry &registry, double time)
{
    auto view = registry.view<Sprite, Position>();
    view.each([&](
                  auto &sprite,
                  auto &position)
              {
        sprite.next_frame(time);

        SDL_Rect src_rect = { static_cast<int>(sprite.width() * sprite.texture().x), static_cast<int>(sprite.height() * sprite.texture().y), sprite.width(), sprite.height() };
        SDL_Rect dst_rect = { static_cast<int>(position.x()), static_cast<int>(position.y()), sprite.width(), sprite.height() };

        SDL_RenderCopy(renderer, sprite.sdl_texture(), &src_rect, &dst_rect); });
}