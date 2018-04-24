//
//  World.h
//  MechaFishASalt
//
//  Created by RYP APP on 4/23/18.
//

#pragma once

#include "cocos2d.h"
USING_NS_CC;

class World : public Layer
{
public:
    int level[8][10];
    Vec2 active[3][3];
    std::vector <Sprite> grid;
    
    static Layer* createLayer();
    virtual bool init();
    
    void startLoad();
    void loadRight();
    void loadLeft();
    void loadUp();
    void loadDown();
    
    void reCache();
    void releaseImages(int a, int b, int c);
    
    CREATE_FUNC(World);
};
