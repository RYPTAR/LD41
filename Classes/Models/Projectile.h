//
//  Projectile.h
//  MechaFishASalt
//
//  Created by RYP APP on 4/24/18.
//

#pragma once
#include "cocos2d.h"
USING_NS_CC;

class Projectile : public Sprite
{
private:
    Vec2 pos;
    int owner;
    
public:
    
    virtual bool init();
    void build();
    void setPos(Vec2 pos);
    void setOwner(int owner);
    
    void runTime(float dt);
    void updatePos(Vec2 pos);
    void destroy();
    
    CREATE_FUNC(Projectile);
};
