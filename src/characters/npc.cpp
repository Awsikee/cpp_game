#include <iostream>
#include <string>

#include <dataDefinition.hpp>
#include "../../inc/characters/npc.hpp"

NPC::NPC()
{

}

NPC::NPC(const char* texturesheet, SDL_Renderer* ren, int x, int y, short age, bool gender, short emotional_state, short speed, std::string name, std::string surname, int* energy ) 
: GameObject(texturesheet,ren,x,y), age(age),gender(gender), emotional_state(emotional_state), speed(speed), name(name), surname(surname), energy(new int(50)){}

NPC::~NPC()
{

}

