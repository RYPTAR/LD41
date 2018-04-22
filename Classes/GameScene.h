//
//  GameScene.h
//  MechaFishASalt
//
//  Created by RYP APP on 4/22/18.
//

#pragma once

#include "cocos2d.h"

USING_NS_CC;

class Game : public Scene
{
public:
    static Scene* createScene();
    virtual bool init();
    
    void menuCloseCallback(Ref* pSender);
    
    void buildWorld();
    void mainThread();
    
    
    /*void pauseGame(Ref* pSender);
    void quitGame(Ref* pSender);*/
    
    CREATE_FUNC(Game);
};
