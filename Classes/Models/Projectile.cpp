//
//  Projectile.cpp
//  MechaFishASalt-mobile
//
//  Created by RYP APP on 4/24/18.
//

#include "Projectile.h"
#include "../Helpers/Constants.h"
#include "../Helpers/Utils.h"

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
}
void Projectile::setPos(Vec2 pos)
{
    this->setPosition(pos);
    this->pos=pos;
    this->schedule(schedule_selector(Projectile::runTime));
}
void Projectile::setOwner(int owner)
{
    this->owner=owner;
}

void Projectile::runTime(float dt)
{
    if(this->pos.x >= Utils::width())
    {
        destroy();
    }
    else
    {
        Vec2 pos = Vec2(this->pos.x+3, this->pos.y);
        this->updatePos(pos);
    }
}
void Projectile::updatePos(Vec2 pos)
{
    this->pos=pos;
    this->setPosition(pos);
}

void Projectile::destroy()
{
    auto gameLayer = Director::getInstance()->getRunningScene()->getChildByTag(TAG_GAME_LAYER);
    unschedule(schedule_selector(Projectile::runTime));
    gameLayer->removeChild(this);
}
