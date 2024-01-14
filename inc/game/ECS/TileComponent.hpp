#ifndef TILECOMPONENTCLASS_HPP
#define TILECOMPONENTCLASS_HPP

#include "ECS.hpp"
#include "PositionComponent.hpp"
#include "SDL.h"
#include "dataDefinition.hpp"

class TileComponent : public Component
{
    public:

        SDL_Texture* texture;
        SDL_Rect srcRect, destRect;
        Vector2D position;


        TileComponent() = default;

        ~TileComponent()
        {
            SDL_DestroyTexture(texture);
        }

        TileComponent(int srcX, int srcY, int x, int y,const char* path)
        {
            texture = TextureManager::LoadTexture(path);
            position.x = static_cast<int>(x);
            position.y = static_cast<int>(y);
            srcRect.x = srcX;
            srcRect.y = srcY;
            srcRect.w =srcRect.h = DEFAULT_TILE_SIZE;

            destRect.x = x;
            destRect.y = y;
            destRect.w = destRect.h = DEFAULT_TILE_SIZE;
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