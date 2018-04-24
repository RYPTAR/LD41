//
//  Player.h
//  MechaFishASalt
//
//  Created by RYP APP on 4/22/18.
//

#pragma once

#include "cocos2d.h"
#include "Projectile.h"

USING_NS_CC;

class Player : public Sprite
{
private:
    int health, level, posX, posY;
    std::vector <Projectile*> fired;
    
public:
    virtual bool init();
    void build();
    
    void atk();
    
    /*void setX(int x);
    int getX();
    
    void setY(int y);
    int getY();*/
    
    CREATE_FUNC(Player);
};
