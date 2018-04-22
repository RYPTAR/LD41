//
//  MainMenuScene.h
//  MechaFishASalt
//
//  Created by RYP APP on 4/21/18.
//

#pragma once

#include "cocos2d.h"

USING_NS_CC;

class MainMenu : public Scene
{
public:
    static Scene* createScene();
    virtual bool init();
    
    void menuCloseCallback(Ref* pSender);
    void startGame(Ref* pSender);
    
    CREATE_FUNC(MainMenu);
};
