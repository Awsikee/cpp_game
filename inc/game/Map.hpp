#ifndef MAPCLASS_HPP
#define MAPCLASS_HPP

#include <string>


class Map{

    public:

    Map(const char* mapfilepath);
    ~Map();

    void loadMap(std::string path, int sizeX, int sizeY);
    void addTile(int srcX, int srcY, int xpos, int ypos, bool isWalkable);

    private:
    const char *mapfilepath;

};

#endif