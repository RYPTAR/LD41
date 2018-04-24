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
    
    this->build();
    return true;
}

void Entity::build()
{
    this->setSpriteFrame("MrTakeout3_hover0.png");
}
