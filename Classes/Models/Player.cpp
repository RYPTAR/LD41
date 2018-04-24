//
//  Player.cpp
//  MechaFishASalt
//
//  Created by RYP APP on 4/22/18.
//

#include "Player.h"
#include "../Helpers/Constants.h"
#include "SimpleAudioEngine.h"

bool Player::init()
{
    if(!Sprite::init())
        return false;
    
    this->build();
    return true;
}

void Player::build()
{
    this->setSpriteFrame("HeroFish_hover0.png");
}

void Player::atk()
{
    auto gameLayer = Director::getInstance()->getRunningScene()->getChildByTag(TAG_GAME_LAYER);
    Projectile* shot = Projectile::create();
    
    shot->setPos(this->getPosition());
    this->fired.push_back(shot);
    gameLayer->addChild(shot);
}

/*void setX(int x)
{
    posX=x;
}
int getX()
{
    return posX;
}

void setY(int y)
{
    posY=y;
}
int getY()
{
    return posY;
}*/
