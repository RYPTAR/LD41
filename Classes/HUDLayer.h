//
//  HUDLayer.h
//  MechaFishASalt
//
//  Created by RYP APP on 4/23/18.
//

#pragma once
#include "cocos2d.h"

USING_NS_CC;

class HUDLayer : public Layer
{
public:
    static Layer* createLayer();
    virtual bool init();
    
    void buildHUD();
    
    CREATE_FUNC(HUDLayer);
};
