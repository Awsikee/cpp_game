#include "../../inc/characters/villager.hpp"
#include <iostream>

Villager::Villager(const char *texturesheet, SDL_Renderer *ren, int x, int y, short age, bool gender, short emotional_state, short speed, std::string name, std::string surname, int *energy)
    : NPC(texturesheet, ren, x, y, age, gender, emotional_state, speed, name, surname, energy)
{
}

Villager::Villager() {}

Villager::~Villager() {}

void Villager::interact(Building &building) // TODO: replace building with placeable object or interactive object defined within boundaries of a building
{
    if (std::abs(building.posX - xpos) <= 1 && std::abs(building.posY - ypos) <= 1)
    {
        // Call the callback function
        building.interact(getEnergyPointer());
    }
}
void Villager::printData()
{

    std::cout << "Name: " << name << std::endl;
    std::cout << "Surname: " << surname << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Emotional State: " << emotional_state << std::endl;
    std::cout << "Energy: " << *getEnergyPointer() << std::endl;
}
