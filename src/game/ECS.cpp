#include "../../inc/game/ECS/ECS.hpp"

void Entity::addGroup(Group mGroup)
{
    groupBitset[mGroup] = true;
    manager.addToGroup(this,mGroup);
}