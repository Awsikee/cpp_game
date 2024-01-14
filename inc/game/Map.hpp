#ifndef MAPCLASS_HPP
#define MAPCLASS_HPP

#include <string>

#define MAP_HEIGTH 20
#define MAP_WIDTH 25


class Map{

    public:

    Map();
    ~Map();

    static void loadMap(std::string path, int sizeX, int sizeY);

    private:

};

#endif