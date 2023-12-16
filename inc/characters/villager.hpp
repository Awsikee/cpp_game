#ifndef VILLAGERCLASS_H
#define VILLAGERCLASS_H

#include "npc.hpp"

class Villager : public NPC{

    public:
        void printData();
        
        Villager();
        Villager(short age, bool gender, short emotional_state, short speed,int posX, int posY, std::string name, std::string surname, int* energy);
        ~Villager();
        
        void interact(Building &building); // TODO: replace building with placeable object or interactive object defined within boundaries of a building
    
};

#endif