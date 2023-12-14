#ifndef BUILDINGCLASS_H
#define BUILDINGCLASS_H


#include <string>
#include <iostream>
//#include "../characters/npc.hpp"

//class NPC;
class Building
{
    public:

        std::string buildingName;

        int posX, posY; // right lower corner

        Building();

        Building(std::string buildingName, int posX, int posY) : buildingName(buildingName, posX, posY){}

        virtual ~Building()
        {
            
        }

        short length, width; // buildingd are two dimensional. Values defined by building type

    virtual void assignCharacter(const std::string characterName) const {
        std::cout << characterName << " has been assigned to " << buildingName << "." << std::endl;
    }
    // virtual void getInfo() const{
    //     std::cout << this->buildingName << " has resident named " << this->residents[0].name << "." << std::endl;
    // }
    virtual void interact(int *arg)
    {
        std::cout << " Interacted with base bulding" << std::endl;
    }



};

#endif
