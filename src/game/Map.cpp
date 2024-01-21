#include "../../inc/game/Map.hpp"
#include "../../inc/game/textureManager.hpp"
#include "../../inc/game/game.hpp"
#include "../../inc/game/ECS/Components.hpp"
#include <fstream>

extern Manager manager;

Map::Map(const char* mapfilepath): mapfilepath(mapfilepath)
{
}

Map::~Map()
{
}

void Map::loadMap(std::string path, int sizeX, int sizeY)
{
    char c;
    std::fstream mapFile;
    mapFile.open(path);

    int srcX, srcY;

    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            mapFile.get(c);
            srcY = atoi(&c) * DEFAULT_TILE_SIZE;
            mapFile.get(c);
            srcX = atoi(&c) * DEFAULT_TILE_SIZE;
            if(srcY == 128)
            {
                this->addTile(srcX, srcY, x * TILE_SIZE_SCALED, y * TILE_SIZE_SCALED, false);
                auto& tcol(manager.addEntity());
                tcol.addComponent<ColliderComponent>("terrain", x * TILE_SIZE_SCALED, y *TILE_SIZE_SCALED);
                tcol.addGroup(groupColliders);
            }
            else
            {
                this->addTile(srcX, srcY, x * TILE_SIZE_SCALED, y * TILE_SIZE_SCALED, true);
            }
            mapFile.ignore();
        }
    }

    mapFile.close();
}

void Map::addTile(int srcX, int srcY, int xpos, int ypos, bool isWalkable)
{
    auto &tile(manager.addEntity());
    tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos, mapfilepath, isWalkable);
    tile.addGroup(groupMap);
}
