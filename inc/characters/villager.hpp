#ifndef VILLAGERCLASS_H
#define VILLAGERCLASS_H

#include "npc.hpp"

class Villager : public NPC{

    public:
        void printData();
        
        Villager();
        Villager(short age, bool gender, short emotional_state, short speed,int posX, int posY);

    
};

#endif