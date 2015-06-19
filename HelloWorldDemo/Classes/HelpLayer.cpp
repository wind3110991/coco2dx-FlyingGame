//
//  HelpLayer.cpp
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/18.
//
//

#include "HelpLayer.h"

bool HelpLayer::init(){
    if(!Layer::init()){
        return false;
    }
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    helpImg = Sprite::create("helpImg1.png");
    helpImg->setAnchorPoint(Vec2(0, 0));
    helpImg->setPosition(0, 0);
    this->addChild(this->helpImg);
    
    return true;
}

void HelpLayer::onEnter()
{
    Node::onEnter();
}

void HelpLayer::onExit()
{
    Node::onExit();
}

HelpLayer::HelpLayer(void)
{
}

HelpLayer::~HelpLayer(void)
{}



