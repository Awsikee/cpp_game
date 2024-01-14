#include "../../inc/game/Map.hpp"
#include "../../inc/game/textureManager.hpp"
#include "../../inc/game/game.hpp"
#include <fstream>

Map::Map()
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
            Game::addTile(srcX, srcY, x * TILE_SIZE_SCALED, y * TILE_SIZE_SCALED);
            mapFile.ignore();
        }
    }

    mapFile.close();
}