#ifndef TILECOMPONENTCLASS_HPP
#define TILECOMPONENTCLASS_HPP

#include "ECS.hpp"
#include "PositionComponent.hpp"
#include "SDL.h"
#include "dataDefinition.hpp"

class TileComponent : public Component
{
    public:
        PositionComponent *transform;
        SpriteComponent *sprite;

        SDL_Rect tileRect;
        int tileID;
        char* path;

        TileComponent() = default;
        TileComponent(int x, int y, int w, int h, int id)
        {
            tileRect.x = x;
            tileRect.y = y;
            tileRect.w = w;
            tileRect.h = h;
            tileID = id;

            switch (tileID)
            {
                case tiles::g:
                    path = "../../assets/grass.png";
                    break;
                case tiles::w:
                    path = "../../assets/water.png";
                    break;
                case tiles::d:
                    path = "../../assets/dirt.png";
                    break;
                default:
                    // add some texture missing to avoid exceptions during execution
                    break;
            }
            
        }

        void init() override
        {
            entity->addComponent<PositionComponent>((float)tileRect.x, (float)tileRect.y, tileRect.w, tileRect.h, 1);
            transform = &entity->getComponent<PositionComponent>();
            entity->addComponent<SpriteComponent>(path);
            sprite = &entity->getComponent<SpriteComponent>();
        }
};

#endif