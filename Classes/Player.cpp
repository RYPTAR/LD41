//
//  Player.cpp
//  MechaFishASalt
//
//  Created by RYP APP on 4/22/18.
//

#include "Player.h"
#include "SimpleAudioEngine.h"

bool Player::init(){
    if(!Sprite::init())
        return false;
    
    this->buildPlayer();
    return true;
}

void Player::buildPlayer(){
    this->setSpriteFrame("HeroFish_hover0.png");
}

void setX(int x){
    posX=x;
}
int getX(){
    return posX;
}

void setY(int y){
    posY=y;
}
int getY(){
    return posY;
}
