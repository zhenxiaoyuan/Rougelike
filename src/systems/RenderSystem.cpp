#include "RenderSystem.hpp"

#include "../components/Sprite.hpp"
#include "../components/Position.hpp"

#include "../utils/Constants.hpp"

void RenderSystem::render(SDL_Renderer *renderer, entt::registry& registry)
{
    auto view = registry.view<Sprite, Position>();
    view.each([&](const auto& sprite, const auto& pos){
        Uint32 frame = SDL_GetTicks() / 200;
        Uint32 sprite_offset_x = frame % 12;
//
        SDL_Rect tmpSrcRect {static_cast<int>(PLAYER_WIDTH * sprite_offset_x), 0, PLAYER_WIDTH, PLAYER_HEIGHT};
        SDL_Rect tmpDestRect {static_cast<int>(pos.m_x), static_cast<int>(pos.m_y), PLAYER_WIDTH, PLAYER_HEIGHT};

        tmpSrcRect.x = PLAYER_WIDTH * sprite_offset_x;
        tmpDestRect.x = pos.m_x;
        tmpDestRect.y = pos.m_y;

        SDL_RenderCopy(renderer, sprite.m_pTexture, &tmpSrcRect, &tmpDestRect); 
    });
}