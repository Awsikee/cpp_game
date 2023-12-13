#ifndef VILLAGERCLASS_H
#define VILLAGERCLASS_H
#include <string>
#include <iostream>
#include "../characters/npc.hpp"
class Building
{
    public:
        std::string buildingName;

        int posX, posY; // right lower corner

        Building();

        virtual ~Building();

        short length, width; // buildingd are two dimensional. Values defined by building type

    virtual void assignCharacter(const NPC& character) const {
        std::cout << character.name << " has been assigned to " << buildingName << "." << std::endl;
    }
};

#endif
