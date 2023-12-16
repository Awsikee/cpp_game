#ifndef MAPCLASS_HPP
#define MAPCLASS_HPP

#define MAP_HEIGTH 20
#define MAP_WIDTH 25

#include "game.hpp"

class Map{

    public:

    Map();
    ~Map();

    void loadMap(int arr[MAP_HEIGTH][MAP_WIDTH]);
    void drawMap();

    private:
    SDL_Rect src, dest;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int map[MAP_HEIGTH][MAP_WIDTH];
    
};

#endif