//
//  Entity.h
//  MechaFishASalt
//
//  Created by RYP APP on 4/23/18.
//

#pragma once

#include "cocos2d.h"

USING_NS_CC;

class Entity :  public Sprite
{
public:
    Vec2 pos;
    int health;
    
    virtual bool init();
    void build();
    
    void damage();
    void die();
    void setPosX(int x);
    void setPosY(int y);
    
    void runTime(float dt);
    
    CREATE_FUNC(Entity);
};
