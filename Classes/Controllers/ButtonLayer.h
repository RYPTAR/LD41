//
//  Butttons.h
//  MechaFishASalt
//
//  Created by RYP APP on 4/23/18.
//

#pragma once
#include "cocos2d.h"
#include "../Models/Player.h"

USING_NS_CC;

class ButtonLayer : public Layer
{
private:
    Player* player;
public:
    static Layer* createLayer();
    virtual bool init();
    
    void buildButtons();
    void setPlayer(Player* player);
    
    CREATE_FUNC(ButtonLayer);
};
