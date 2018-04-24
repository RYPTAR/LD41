#include "MainMenuScene.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "Utils.h"
#include "Constants.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    return MainMenu::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    auto size = Utils::size();
    Vec2 origin = Utils::origin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainMenu::menuCloseCallback, this));
    
//TODO: FIX SPRITE SHEET
    auto playButton = MenuItemSprite::create(
                                            Sprite::createWithSpriteFrameName("LaunchButton0.png"),
                                            Sprite::createWithSpriteFrameName("LaunchButton1.png"),
                                            CC_CALLBACK_1(MainMenu::startGame, this));
    
    
    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    { problemLoading("'CloseNormal.png' and 'CloseSelected.png'"); }
    else
    {
        float x = origin.x + size.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }
    if (playButton == nullptr ||
        playButton->getContentSize().width <= 0 ||
        playButton->getContentSize().height <= 0)
    { problemLoading("'HeroFish_idle0.png' and 'HeroFish_idleShot0.png'"); }
    else
    {
        float x = origin.x + size.width/2;
        float y = origin.y + size.height*(7/10) + playButton->getContentSize().height;
        playButton->setPosition(Vec2(x,y));
        
        //playButton->setPosition(Vec2(size.width/2 + origin.x, size.height*(3/4)-  + origin.y));
        CCLOG("LOADED");
    }
    
    // create menu, it's an autorelease object
    auto menu = Menu::create();
    menu->addChild(closeItem);
    menu->addChild(playButton);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    /*auto label = Label::createWithTTF("MainMenuScene", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr){ problemLoading("'fonts/Marker Felt.ttf'"); }
    else{
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + size.width/2,
                                origin.y + size.height - label->getContentSize().height));
        // add the label as a child to this layer
        this->addChild(label, 1);
    }*/
    
    // add Background
    auto background = Sprite::create("MainMenuBG.png");
    if (background == nullptr){ problemLoading("'MainMenuBG.png'"); }
    else
    {
        // position the sprite on the center of the screen
        background->setPosition(Vec2(size.width/2 + origin.x, size.height/2 + origin.y));
        
        // add the sprite as a child to this layer
        this->addChild(background, 0);
    }
    
    auto title = Sprite::create("MainMenuTitle.png");
    if (title == nullptr){ problemLoading("'MainMenuTitle.png'"); }
    else
    {
        title->setPosition(Vec2(origin.x + size.width/2,
                                origin.y + size.height - title->getContentSize().height));
        this->addChild(title, 0);
    }
    
    return true;
}


void MainMenu::menuCloseCallback(Ref* pSender)
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

void MainMenu::startGame(Ref* pSender)
{
    //CCLOG("GAME");
    Director::getInstance()->replaceScene(Game::createScene());
}
