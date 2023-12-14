#include <iostream>
//#include "../inc/include/SDL2/SDL.h"
#include "inc/dataDefinition.hpp"
#include "inc/characters/villager.hpp"
#include "inc/buildings/smallHouse.hpp"
#include "inc/characters/NPC.hpp"

int main(int argc, char* argv[])
{
    SmallHouse smallHouse("Nice place", 10, 20);
    int defaultEnergy = 50;
    Villager villager(45,male,fine,1,0,0, "robert", "jr", &defaultEnergy);

    smallHouse.assignCharacter(villager);
    villager.interact(smallHouse);
    //std::cout  << "Energy: " << static_cast<int>(*villager.energy) << std::endl;
    villager.printData();
    smallHouse.getInfo();
    //Villager villager;
    //villager.
    return 0;
}