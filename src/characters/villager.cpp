#include "../../inc/characters/villager.hpp"
#include <iostream>
Villager::Villager(short age, bool gender, short emotional_state, short speed, int posX, int posY, std::string name, std::string surname, int *energy)
    : NPC(age, gender, emotional_state, speed, posX, posY, name, surname, energy)
{
}

Villager::Villager() {}

Villager::~Villager() {}

void Villager::interact(Building &building) // TODO: replace building with placeable object or interactive object defined within boundaries of a building
{
    if (std::abs(building.posX - this->posX) <= 1 && std::abs(building.posY - this->posY) <= 1)
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
