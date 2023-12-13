#include <iostream>
#include <string>

#include <dataDefinition.hpp>
#include "../../inc/characters/npc.hpp"

NPC::NPC()
{

}

NPC::NPC(short age, bool gender, short emotional_state, short speed, int posX, int posY) 
: age(age),gender(gender), emotional_state(emotional_state), speed(speed), posX(posX), posY(posY){}

NPC::~NPC()
{

}
