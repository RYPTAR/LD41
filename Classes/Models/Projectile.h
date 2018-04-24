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
    bool traveling;
    Vec2 pos;
    
public:
    
    virtual bool init();
    void build();
    void setPos(Vec2 pos);
    
    void runTime(float dt);
    
    CREATE_FUNC(Projectile);
};
