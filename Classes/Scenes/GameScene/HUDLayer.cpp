//
//  HUDLayer.cpp
//  MechaFishASalt
//
//  Created by RYP APP on 4/23/18.
//

#include "HUDLayer.h"

USING_NS_CC;

Layer* HUDLayer::createLayer()
{
    auto layer = Layer::create();
    return layer;
}

bool HUDLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    this->buildHUD();
    return true;
}

void HUDLayer::buildHUD()
{
    
}
