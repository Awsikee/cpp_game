#define SDL_MAIN_HANDLED
#include <iostream>

#include "inc/dataDefinition.hpp"
#include "inc/characters/villager.hpp"
#include "inc/buildings/smallHouse.hpp"
#include "inc/characters/NPC.hpp"
#include "inc/game/game.hpp"

Game *game = nullptr;

int main()
{
    SDL_SetMainReady();

    game = new Game();

    game->init("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    SmallHouse smallHouse("Nice place", 10, 20);
    int defaultEnergy = 50;
    Villager villager(45,male,fine,1,0,0, "robert", "jr", &defaultEnergy);

    smallHouse.assignCharacter(villager);
    villager.interact(smallHouse);
    //std::cout  << "Energy: " << static_cast<int>(*villager.energy) << std::endl;
    villager.printData();
    smallHouse.getInfo();


    while(game->running())
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
    //Villager villager;
    //villager.
    return 0;
}