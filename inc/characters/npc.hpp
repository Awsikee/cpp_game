#ifndef NPCCLASS_H
#define NPCCLASS_H

#include <string>

class NPC
{
    public: //make everything public temporarly

    short age;
    bool gender;
    short emotional_state;


    /*
    hunger
    */

    short speed;

    int posX, posY;

    //NPC parent1, parent2; // optional
    std::string name, surname;

    NPC();
    NPC(short age, bool gender, short emotional_state, short speed, int posX, int posY);
    virtual ~NPC();

};

#endif