#include "RenderSystem.hpp"

#include <iostream>

#include "../components/Sprite.hpp"
#include "../components/Position.hpp"

void RenderSystem::render(SDL_Renderer *renderer, entt::registry &registry)
{
    auto view = registry.view<Sprite, Position>();
    view.each([&](
                  auto &sprite,
                  auto &position)
              {
        Uint32 frame = SDL_GetTicks() / 200;
        Uint32 sprite_offset_x = frame % 12;

        SDL_Rect src_rect = { static_cast<int>(sprite.width() * sprite_offset_x), 0, sprite.width(), sprite.height() };
        SDL_Rect dst_rect = { static_cast<int>(position.x()), static_cast<int>(position.y()), sprite.width(), sprite.height() };

        SDL_RenderCopy(renderer, sprite.texture(), &src_rect, &dst_rect); });

}