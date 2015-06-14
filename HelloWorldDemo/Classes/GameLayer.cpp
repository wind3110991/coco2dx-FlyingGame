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
    gameStatus = GAME_STATUS_READY;
    this->score = 0;//重置分数
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto label = Label::createWithTTF("Your Score: ","fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/10,origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label);
    
    ostringstream  ostr;
    ostr << this->score;
    string str(ostr.str());
    
    this->scoreLabel = Label::create(str,"fonts/Marker Felt.ttf", 24);
    this->scoreLabel->setVisible(true); //计分开始
    scoreLabel->setPosition(Vec2(origin.x + visibleSize.width/6 + 20 ,origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(scoreLabel);
    
    //实例化飞机
    this->airplane = GameAirplaneObj::getInstance();
    this->airplane->createAirplane();
    PhysicsBody *body = PhysicsBody::create();
    body->addShape(PhysicsShapeCircle::create(AIRPLANE_RADIUS));
    body->setDynamic(true);
    body->setLinearDamping(0.0f);
    body->setGravityEnable(true);
    airplane->setPosition(Vec2(visibleSize.width/3 + origin.x, visibleSize.height/3 + origin.y));
    airplane->setPhysicsBody(body);
    body->setContactTestBitmask(0xFFFFFFFF);
    airplane->idle();
    addChild(airplane,0);
    this->scheduleUpdate();
//    auto dispatcher = Director::getInstance()->getEventDispatcher();
//    auto contactListener = EventListenerPhysicsContact::create();
//    contactListener->onContactBegin = CC_CALLBACK_1(GameLayer::onContactBegin, this);
//    dispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
    return true;
}

void GameLayer::onEnter()
{
    Layer::onEnter();
    
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameLayer::onContactBegin, this);
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    
    dispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
}


void GameLayer::onTouch()
{
    if(this->gameStatus == GAME_STATUS_OVER) {
        return;
    }
    //加音效
    if(this->gameStatus == GAME_STATUS_READY) {
        //this->delegator->onGameStart();
        //this->gameStart();
        this->airplane->bounce();
        this->gameStatus = GAME_STATUS_START;
        //this->createMonster();
    }else if(this->gameStatus == GAME_STATUS_START) {
        this->airplane->getPhysicsBody()->setVelocity(Vect(0, 260));
    }
}


bool GameLayer::onContactBegin(const PhysicsContact& contact) {
    this->gameOver();
    return true;
}

bool GameLayer::checkHit()
{
    if(this->airplane->getPositionX())  return true;
    return false;
}

void GameLayer::gameStart()
{
    
    gameStatus = GAME_STATUS_READY;
    this->scheduleUpdate();//启动默认更新

}

//此处留有接口,处理游戏结束后的后勤工作
void GameLayer::gameOver()
{
    if(this->gameStatus == GAME_STATUS_OVER) {
        return;
    }
    this->gameStatus = GAME_STATUS_OVER;
    this->airplane->stopAllActions();
}

void GameLayer::update(float delta)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    if(gameStatus == GAME_STATUS_START)
    {
        this->score += 1;
        
        ostringstream  ostr;
        ostr << this->score;
        string str(ostr.str());
        
        this->scoreLabel->setString(str);
        this->scoreLabel->setVisible(true);
    }
    
    //地面碰撞检测
    else if(gameStatus == GAME_STATUS_START&&airplane->getPositionY() < 800)
    {
        this->gameStatus = GAME_STATUS_OVER;
        this->airplane->stopAllActions();
    }
    else if(gameStatus == GAME_STATUS_OVER)
    {
        auto label = Label::createWithTTF("Game Over!","fonts/Marker Felt.ttf", 40);
        label->setPosition(Vec2((origin.x + visibleSize.width)/2,(origin.y + visibleSize.height - label->getContentSize().height)/2));
        this->addChild(label);
        unscheduleUpdate();
    }
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
