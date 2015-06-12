//
//  GameOptionLayer.cpp
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/13.
//
//

#include "GameOptionLayer.h"

GameOptionLayer::GameOptionLayer()
{}

GameOptionLayer::~GameOptionLayer()
{}

bool GameOptionLayer::init()
{
    if(Layer::init()){
        auto dispatcher = Director::getInstance()->getEventDispatcher();
        auto listener = EventListenerTouchAllAtOnce::create();
        listener->onTouchesBegan = CC_CALLBACK_2(GameOptionLayer::onTouchesBegan, this);
        dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
        
        return true;
    }else {
        return false;
    }
}

void GameOptionLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event *event)
{
    this->delegator->onTouch();
}