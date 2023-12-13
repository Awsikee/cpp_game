#include "../../inc/characters/villager.hpp"
#include <iostream>
Villager::Villager(short age, bool gender, short emotional_state, short speed,int posX, int posY) 
: NPC(age, gender, emotional_state, speed, posX, posY)
{}

Villager::Villager()
{

}


void Villager::printData()
{
    std::cout  << "Name: " << this->name << std::endl;
    std::cout  << "Surname: " << this->surname << std::endl;
    std::cout  << "Age: " << this->age << std::endl;
    std::cout  << "Gender: " << this->gender << std::endl;
    std::cout  << "Emotional State: " << this->emotional_state << std::endl;
}
