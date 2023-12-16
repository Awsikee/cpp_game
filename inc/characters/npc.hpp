#ifndef NPCCLASS_H
#define NPCCLASS_H

#include <string>
#include "../buildings/building.hpp"

using namespace std;
class NPC
{
    private:
    int* energy; 

    public: //make everything public temporarly

    short age;
    bool gender;
    short emotional_state;

    uint8_t hunger; // depelled with time. repelled by food. Requires food item
    uint8_t health; // depelled by events
    
    short speed;

    int posX, posY;

    //NPC parent1, parent2; // optional
    string name, surname;

    NPC();
    NPC(short age, bool gender, short emotional_state, short speed, int posX, int posY, string name, string surname, int* energy);
    virtual ~NPC();

    // Getter for energy
    int* getEnergyPointer()const;

    //TBD
    // movement
    // ai
    // needs
    // talk

};

#endif