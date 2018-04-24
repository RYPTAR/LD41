//
//  Projectile.cpp
//  MechaFishASalt-mobile
//
//  Created by RYP APP on 4/24/18.
//

#include "Projectile.h"

bool Projectile::init()
{
    if(!Sprite::init())
        return false;
    
    this->build();
    return true;
}

void Projectile::build()
{
    this->setSpriteFrame("HeroFish_Atk0.png");
    this->traveling= true;
}
void Projectile::setPos(Vec2 pos)
{
    this->setPosition(pos);
    this->pos=pos;
}

void Projectile::runTime(float dt)
{

}
