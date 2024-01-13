#include "../../inc/game/Map.hpp"
#include "../../inc/game/textureManager.hpp"


//temporary map

int basicMap[MAP_HEIGTH][MAP_WIDTH] =
{
    {g,g,g,g,g,g,g,g,g,g,g,w,w,g,g,g,g,g,g,g,g,d,d,d,g},
    {g,g,g,g,g,g,g,g,g,g,g,w,w,g,g,g,g,g,g,g,g,g,d,d,g},
    {g,g,g,g,g,g,g,g,g,g,g,w,w,g,g,g,g,g,g,g,g,g,g,g,g},
    {g,g,g,g,g,g,g,g,g,g,g,g,w,g,g,g,g,g,g,g,g,g,g,g,g},
    {g,g,g,g,g,g,g,g,g,g,g,g,w,w,g,g,g,g,g,g,g,g,g,g,g},
    {g,g,g,g,g,g,g,g,g,g,g,g,w,w,g,g,g,g,g,d,d,g,g,g,g},
    {g,g,g,g,g,g,g,g,g,g,g,g,g,w,w,g,g,g,d,d,g,g,g,g,g},
    {g,g,g,g,d,g,g,g,g,g,g,g,g,g,w,g,g,g,g,d,g,g,g,g,g},
    {g,g,g,g,d,d,g,g,g,g,g,g,g,g,w,g,g,g,g,g,g,g,g,g,g},
    {g,g,g,g,d,d,d,g,g,g,g,g,g,g,w,g,g,g,g,g,g,g,g,g,g},
    {g,g,g,g,g,d,g,g,g,g,g,g,g,g,w,w,g,g,g,g,g,g,g,g,g},
    {g,g,g,g,g,d,d,g,g,g,g,g,g,g,w,g,g,g,g,g,g,g,g,g,g},
    {g,g,g,g,g,d,g,g,g,g,g,g,g,g,w,g,g,g,g,g,g,g,g,g,g},
    {g,g,g,g,g,g,g,g,g,g,g,g,g,g,w,g,g,g,g,g,g,g,g,g,g},
    {g,g,g,g,g,g,g,g,g,g,g,g,g,g,w,w,g,g,g,g,g,g,g,g,g},
    {g,g,g,g,g,g,g,g,g,g,g,g,g,g,w,g,w,w,g,g,g,g,g,g,g},
    {g,g,g,g,g,g,g,g,g,g,g,g,g,g,w,g,g,g,w,g,g,g,g,g,g},
    {g,g,g,g,g,g,g,g,g,g,g,g,g,g,w,g,g,g,g,w,g,g,g,g,g},
    {g,g,g,g,g,g,g,g,g,g,g,g,g,g,w,w,g,g,g,g,w,g,g,g,g},
    {g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,w,w,g,g,g,g,w,g,g,g}
};

Map::Map():
    dirt(TextureManager::LoadTexture("../../assets/dirt.png")), 
    grass(TextureManager::LoadTexture("../../assets/grass.png")), 
    water(TextureManager::LoadTexture("../../assets/water.png"))
{
    loadMap(basicMap);

    src.x = src.y = 0;
    src.w = dest.w = src.h = dest.h = DEFAULT_TILE_SIZE;

    dest.x = dest.y = 0;
}

Map::~Map()
{
    SDL_DestroyTexture(grass);
    SDL_DestroyTexture(water);
    SDL_DestroyTexture(dirt);
}

void Map::loadMap(int arr[MAP_HEIGTH][MAP_WIDTH])
{
    for (int row = 0; row < MAP_HEIGTH; row++){
        for(int column =0; column < MAP_WIDTH; column++)
        {
            map[row][column] = arr[row][column];
        }
    }

}

void Map::drawMap()
{
    int type = 0;

    for (int row = 0; row < MAP_HEIGTH; row++){
        for(int column =0; column < MAP_WIDTH; column++)
        {
            type = map[row][column];

            dest.x = column * DEFAULT_TILE_SIZE;
            dest.y = row *DEFAULT_TILE_SIZE;

            switch (type)
            {
                case g:
                    TextureManager::Draw(grass,src,dest);
                    break;
                case w:
                    TextureManager::Draw(water,src,dest);
                    break;
                case d:
                    TextureManager::Draw(dirt,src,dest);
                    break;
                default:
                    break;
            }
        }
    }
}