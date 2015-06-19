//
//  AboutLayer.cpp
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/19.
//
//

#include "AboutLayer.h"

//AboutLayer类
bool AboutLayer::init(){
    if(!Layer::init()){
        return false;
    }
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    aboutImg = Sprite::create("aboutMe.png");
    aboutImg->setAnchorPoint(Vec2(0, 0));
    aboutImg->setPosition(0, 0);
    this->addChild(this->aboutImg);
    
    return true;
}

void AboutLayer::onEnter()
{
    Node::onEnter();
}

void AboutLayer::onExit()
{
    Node::onExit();
}

AboutLayer::AboutLayer(void)
{
}

AboutLayer::~AboutLayer(void)
{}