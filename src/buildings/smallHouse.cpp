#include "../../inc/buildings/smallHouse.hpp"

void SmallHouse::repell_energy(int *arg)
{
    *arg = 100;
}

SmallHouse::SmallHouse(){}

SmallHouse::SmallHouse(std::string name, int posX, int posY) : Building(name, posX, posY)
{
    for (size_t i = 0; i < MAX_RESIDENTS_SM; ++i)
    {
        residents[i].name = "DefaultNPC" + std::to_string(i + 1);
    }
}
SmallHouse::~SmallHouse(){};

void SmallHouse::assignCharacter(const NPC &character)
{
    // Check if there's space in the residents array
    if (sizeof(residents) / sizeof(residents[0]) > 0)
    {
        this->residents[0] = character;
    }
    else
    {
        std::cerr << "Cannot assign more characters to SmallHouse. Residents array is full." << std::endl;
    }
}
void SmallHouse::get_address() {} //

void SmallHouse::getInfo()
{

    std::cout << this->buildingName << " has resident named " << this->residents[0].name << "." << std::endl;
}

void SmallHouse::interact(int *arg)
{
    // std::cout << " Interacted with"<< buildingName << std::endl;
    repell_energy(arg);
}