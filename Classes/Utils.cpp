//
//  Utils.cpp
//  MechaFishASalt
//
//  Created by RYP APP on 4/24/18.
//

#include "Utils.h"
#include "Constants.h"

USING_NS_CC;

static float scale = 1.0f;
static int scaleFactor = 1;

Size Utils::screenRes()
{
    return Director::getInstance()->getWinSizeInPixels();
}

Size Utils::size()
{
    return Director::getInstance()->getVisibleSize();
}
float Utils::width()
{
    return size().width;
}
float Utils::height()
{
    return size().height;;
}

Vec2 Utils::origin()
{
    return Director::getInstance()->getVisibleOrigin();
}

Vec2 Utils::center()
{
    Vec2 center;
    center.x = screenRes().width / 2;
    center.y = screenRes().height / 2;
    return center;
}

void Utils::scaleSprite(Sprite* sprite)
{
    float rX = Utils::screenRes().width / sprite->getContentSize().width;
    float rY = Utils::screenRes().height / sprite->getContentSize().height;
    
    sprite->setScale(rX,rY);
}

float Utils::getScale()
{
    return scale;
}

void Utils::setScale(float s)
{
    scale = s;
}

float Utils::getScaleFactor()
{
    return scaleFactor;
}

void Utils::setScaleFactor(int sf)
{
    scaleFactor = sf;
}
