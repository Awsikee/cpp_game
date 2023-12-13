#include <iostream>
//#include "SDL2/SDL.h"
#include "dataDefinition.hpp"
#include "../inc/characters/villager.hpp"
#include "../inc/characters/NPC.hpp"

int main(int argv, char** args)
{
    Villager villager(45,male,fine,1,0,0);
    
    villager.printData();
    //Villager villager;
    //villager.
    return 0;
}