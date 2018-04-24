//
//  Utils.h
//  MechaFishASalt
//
//  Created by RYP APP on 4/24/18.
//

#pragma once

#include "cocos2d.h"
USING_NS_CC;

class Utils
{
    
public:
    
    static Size screenRes();
    static Size size();
    static float width();
    static float height();
    static Vec2 origin();
    static Vec2 center();
    static void scaleSprite(Sprite* sprite);
    static float getScale();
    static void setScale(float s);
    static float getScaleFactor();
    static void setScaleFactor(int sf);
};
