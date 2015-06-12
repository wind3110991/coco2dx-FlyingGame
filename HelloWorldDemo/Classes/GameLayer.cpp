//
//  GameLayer.cpp
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/13.
//
//

#include "GameLayer.h"

GameLayer::GameLayer()
{
    
}
GameLayer::~GameLayer()
{
    
}

bool GameLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    this->gameStatus = GAME_STATUS_READY;
    //this->score = 0;

    //实例化飞机
    this->airplane = GameAirplaneObj::getInstance();
    this->airplane->createAirplane();
    PhysicsBody *body = PhysicsBody::create();
    body->addShape(PhysicsShapeCircle::create(AIRPLANE_RADIUS));
    body->setDynamic(true);
    body->setLinearDamping(0.0f);
    body->setGravityEnable(true);
    airplane->setPhysicsBody(body);
    airplane->idle();
    addChild(airplane,0);
    
 //   auto contactListener = EventListenerPhysicsContact::create();
 //   contactListener->onContactBegin = CC_CALLBACK_2(GameLayer::onContactBegin, this);
 //   this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    
    return true;
}



void GameLayer::onTouch()
{
    if(this->gameStatus == GAME_STATUS_OVER) {
        return;
    }
    //加音效
    if(this->gameStatus == GAME_STATUS_READY) {
        //this->delegator->onGameStart();
        this->airplane->bounce();
        this->gameStatus = GAME_STATUS_START;
        //this->createMonster();
    }else if(this->gameStatus == GAME_STATUS_START) {
        this->airplane->getPhysicsBody()->setVelocity(Vect(0, 260));
    }
}
//
//void GameLayer::onEnterTransitionDidFinish()
//{
//    Node::onEnterTransitionDidFinish();
//    
//    // 场景加载完毕才滚动背景
//    this->scheduleUpdate();
//}

bool GameLayer::onContactBegin(EventCustom *event, const PhysicsContact& contact) {
    this->gameOver();
    return true;
}

//此处留有接口,处理游戏结束后的后勤工作
void GameLayer::gameOver()
{
}


void GameLayer::setover()
{
    Menu* pMenu = (Menu *)this->getChildByTag(25);
    pMenu->setVisible(true);
    pMenu->setEnabled(true);
    gameover->setVisible(true);
    gameover->setScale(0);
    pMenu->setScale(0);
    pMenu->runAction(CCScaleTo::create(0.5,1));
    gameover->runAction(CCScaleTo::create(0.5,0.5));
    isover = true;
    
}


