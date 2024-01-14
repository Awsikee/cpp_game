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
    char tile;
    std::fstream mapFile;
    mapFile.open(path);

    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            mapFile.get(tile);
            Game::addTile(atoi(&tile), x * DEFAULT_TILE_SIZE *GAMESCALE, y * DEFAULT_TILE_SIZE*GAMESCALE);
            mapFile.ignore();
        }
    }

    mapFile.close();
}