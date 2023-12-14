#include "../../inc/buildings/building.hpp"

Building::Building(): buildingName("building"), posX(0), posY(0)  {}

Building::Building(std::string buildingName, int posX, int posY) : buildingName(buildingName), posX(posX), posY(posY) {}

Building::~Building() {}

void Building::assignCharacter(const std::string characterName) const
{
    std::cout << characterName << " has been assigned to " << buildingName << "." << std::endl;
}

void Building::interact(int *arg)
{
    std::cout << " Interacted with base bulding" << std::endl;
}