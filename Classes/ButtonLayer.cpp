//
//  Buttons.cpp
//  MechaFishASalt
//
//  Created by RYP APP on 4/23/18.
//

#include "ButtonLayer.h"
#include "ui/CocosGUI.h"
#include "Constants.h"
#include "Utils.h"

USING_NS_CC;

Layer* ButtonLayer::createLayer()
{
    auto layer = Layer::create();
    return layer;
}
bool ButtonLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    this->buildButtons();
    return true;
}
void ButtonLayer::buildButtons()
{
    auto button = ui::Button::create("Primary0.png", "Primary1.png", "Primary1.png", ui::Widget::TextureResType::PLIST);
    //button->setTitleText("Button Text");
    
    button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                CCLOG("Button 1 clicked");
                break;
            default:
                break;
        }
    });
    
    button->setPosition(Vec2(Utils::width()*(.9), Utils::height()/10));
    
    this->addChild(button);
}
