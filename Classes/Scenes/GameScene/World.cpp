//
//  World.cpp
//  MechaFishASalt
//
//  Created by RYP APP on 4/23/18.
//

#include "World.h"
#include "cocos2d.h"
#include "../../Helpers/Constants.h"
#include <vector>
USING_NS_CC;

Layer* World::createLayer()
{
    // 'layer' is an autorelease object
    auto layer = Layer::create();
    
    return layer;
}

bool World::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    this->startLoad();
    
    return true;
}

void World::startLoad()
{
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 10; ++j)
        {
            level[i][j] = (j+1) * (i+1);
        }
    }
    
    /*grid.push_back(Sprite::create("./World/Level/Foreground/1.png"));
    grid.push_back(Sprite::create("./World/Level/Foreground/2.png"));
    grid.push_back(Sprite::create("./World/Level/Foreground/3.png"));*/
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    float col2 = visibleSize.width/2 + origin.x;
    float row2 = visibleSize.height/2 + origin.y;
    float col1 = col2 - 2000;
    float row1 = row2 - 1000;
    float col3 = col2 + 2000;
    float row3 = row2 + 2000;
    
    auto bg1 = Sprite::create("./World/Level1/Foreground/32.png");
    bg1->setPosition(Vec2(col1, row1));
    auto bg2 = Sprite::create("./World/Level1/Foreground/33.png");
    bg2->setPosition(Vec2(col2, row1));
    auto bg3 = Sprite::create("./World/Level1/Foreground/34.png");
    bg3->setPosition(Vec2(col3, row1));
    auto bg4 = Sprite::create("./World/Level1/Foreground/42.png");
    bg4->setPosition(Vec2(col1,row2));
    auto bg5 = Sprite::create("./World/Level1/Foreground/43.png");
    bg5->setPosition(Vec2(col2,row2));
    auto bg6 = Sprite::create("./World/Level1/Foreground/44.png");
    bg6->setPosition(Vec2(col3,row2));
    auto bg7 = Sprite::create("./World/Level1/Foreground/52.png");
    bg7->setPosition(Vec2(col1,row3));
    auto bg8 = Sprite::create("./World/Level1/Foreground/53.png");
    bg8->setPosition(Vec2(col2,row3));
    auto bg9 = Sprite::create("./World/Level1/Foreground/54.png");
    bg9->setPosition(Vec2(col3,row3));
    
    
    // add the sprite as a child to this layer
    this->addChild(bg1, 0);
    this->addChild(bg2, 0);
    this->addChild(bg3, 0);
    this->addChild(bg4, 0);
    this->addChild(bg5, 0);
    this->addChild(bg6, 0);
    this->addChild(bg7, 0);
    this->addChild(bg8, 0);
    this->addChild(bg9, 0);
    
    
}
