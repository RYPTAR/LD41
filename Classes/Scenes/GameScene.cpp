//
//  GameScene.cpp
//  MechaFishASalt-mobile
//
//  Created by RYP APP on 4/22/18.
//

#include "GameScene.h"
#include "./GameScene/World.h"
#include "SimpleAudioEngine.h"

#include "../Helpers/Constants.h"
#include "../Helpers/Utils.h"
#include "../Models/Player.h"
#include "../Models/Entity.h"
#include "../Controllers/Joystick.h"
#include "../Controllers/ButtonLayer.h"

USING_NS_CC;

Scene* Game::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Game::create();
    scene->setTag(TAG_GAME_SCENE);
    
    // 'layer' is an autorelease object
    auto layer = Layer::create();
    layer->setTag(TAG_GAME_LAYER);
    
    // add layer as a child to scene
    scene->addChild(layer, 0, TAG_GAME_LAYER);
    
    // return the scene
    return scene;
    
    //THIS IS AUTO GEN CODE FOR A NEW SCENE SO ITS GOOOD
    //Time to build basic 1 background scene with Quite and Paul
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Game::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    this->buildWorld();
    
    return true;
}

void Game::buildWorld()
{
    auto size = Utils::size();
    Vec2 origin = Utils::origin();

    auto player = Player::create();
    player->setPosition(Vec2(size.width/2 + origin.x, size.height/2 + origin.y));
    player->setTag(TAG_PLAYER);
    
    /*auto background = Sprite::create("Stars0.png");
    if (background == nullptr)
    {
        problemLoading("'Stars0.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        background->setPosition(Vec2(size.width/2 + origin.x, size.height/2 + origin.y));
        
        // add the sprite as a child to this layer
        this->addChild(background, 0);
    }*/

    this->addChild(player,3);
    
    auto joystick = Joystick::create();
    joystick->setMainChar(player);
    joystick->setSpeed(0.1f);
    joystick->setLimitScreen(true);
    joystick->setTouchShow(true);
    this->addChild(joystick,4);
    
    auto buttons = ButtonLayer::create();
    buttons->setPlayer(player);
    buttons->setTag(TAG_BUTTON_LAYER);
    this->addChild(buttons,4);
    
    this->schedule(schedule_selector(Game::mainThread));
}

void Game::mainThread(float dt)
{
    this->rng = std::rand() % 30;
    if(this->rng == 1)
    {
        this->spawnMinion();
    }
}

void Game::spawnMinion()
{
    //TODO: Randomize spawn locations
    auto size = Utils::size();
    Vec2 origin = Utils::origin();
    auto rngX = std::rand() % (int)size.width;
    auto rngY = std::rand() % (int)size.height;
    CCLOG("rngX: %d, rngY: %d", rngX, rngY);
    CCLOG("sizeW: %f, sizeH: %f", size.width, size.height);
    
    
    
    auto minion = Entity::create();
    minion->setPosition(Vec2(rngX+ origin.x, rngY + origin.y));
    this->addChild(minion);
}

void Game::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
}
