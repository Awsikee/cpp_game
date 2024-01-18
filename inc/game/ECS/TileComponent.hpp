#ifndef TILECOMPONENTCLASS_HPP
#define TILECOMPONENTCLASS_HPP

#include "ECS.hpp"
#include "PositionComponent.hpp"
#include "SDL.h"
#include "dataDefinition.hpp"

class TileComponent : public Component
{
    public:
        int g, h, f;

        SDL_Texture* texture;
        SDL_Rect srcRect, destRect;
        Vector2D position;
        Vector2D tileMiddle;

        bool isWalkable;


        TileComponent() = default;

        ~TileComponent()
        {
            SDL_DestroyTexture(texture);
        }

        TileComponent(int srcX, int srcY, int x, int y, const char* path, bool isWalkable)
        {
            texture = TextureManager::LoadTexture(path);
            position.x = static_cast<int>(x);
            position.y = static_cast<int>(y);
            srcRect.x = srcX;
            srcRect.y = srcY;
            srcRect.w =srcRect.h = DEFAULT_TILE_SIZE;

            destRect.x = x;
            destRect.y = y;
            destRect.w = destRect.h = TILE_SIZE_SCALED;

            tileMiddle.x = position.x + DEFAULT_TILE_SIZE/2;
            tileMiddle.y = position.y + DEFAULT_TILE_SIZE/2;
            isWalkable = isWalkable;
        }

        void update() override
        {
            destRect.x = position.x - Game::camera.x;
            destRect.y = position.y - Game::camera.y;
        }

        void draw( ) override
        {
            TextureManager::Draw(texture, srcRect,destRect);
        }


};

#endif