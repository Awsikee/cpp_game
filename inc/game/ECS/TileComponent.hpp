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


        TileComponent() = default;

        ~TileComponent()
        {
            SDL_DestroyTexture(texture);
        }

        TileComponent(int srcX, int srcY, int x, int y,const char* path)
        {
            texture = TextureManager::LoadTexture(path);
            srcRect.x = srcX;
            srcRect.y = srcY;
            srcRect.w =srcRect.h = DEFAULT_TILE_SIZE;

            destRect.x = x;
            destRect.y = y;
            destRect.w = destRect.h = DEFAULT_TILE_SIZE;
        }

        void draw( ) override
        {
            TextureManager::Draw(texture, srcRect,destRect);
        }


};

#endif