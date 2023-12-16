#ifndef NPCCLASS_H
#define NPCCLASS_H

#include <string>
#include "../buildings/building.hpp"
#include "../game/GameObject.hpp"

using namespace std;
class NPC : public GameObject
{
private:
    int *energy;

public: // make everything public temporarly
    short age;
    bool gender;
    short emotional_state;

    uint8_t hunger; // depelled with time. repelled by food. Requires food item
    uint8_t health; // depelled by events

    short speed;

    // NPC parent1, parent2; // optional
    string name, surname;

    NPC();
    NPC(const char *texturesheet, SDL_Renderer *ren, int x, int y, short age, bool gender, short emotional_state, short speed, string name, string surname, int *energy);
    virtual ~NPC();

    // Getter for energy
    inline int *getEnergyPointer() const { return energy; }

    // TBD
    //  movement
    //  ai
    //  needs
    //  talk
};

#endif