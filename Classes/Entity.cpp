//
//  Entity.cpp
//  MechaFishASalt
//
//  Created by RYP APP on 4/23/18.
//

#include "Entity.h"

USING_NS_CC;

bool Entity::init()
{
    if(!Sprite::init())
        return false;
    
    this->buildEntity();
    return true;
}

void Entity::buildEntity()
{
    this->setSpriteFrame("MrTakeout3_hover0.png");
}
