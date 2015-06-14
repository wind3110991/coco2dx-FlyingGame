//
//  GameAirplaneObj.cpp
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/9.
//
//

#include "GameAirplaneObj.h"

GameAirplaneObj::GameAirplaneObj()
{
    
}

GameAirplaneObj::~GameAirplaneObj()
{
    
}

bool GameAirplaneObj::init()
{
    this->isFirstTime = 3;
    return true;
}

GameAirplaneObj* GameAirplaneObj::shareAirplaneObj = nullptr;
GameAirplaneObj* GameAirplaneObj::getInstance()
{
    if(shareAirplaneObj == NULL){
        shareAirplaneObj = new GameAirplaneObj();
        if(!shareAirplaneObj->init()){
            delete(shareAirplaneObj);
            shareAirplaneObj = NULL;
            CCLOG("ERROR: Could not init shareAirplaneObj");
        }
    }
    return shareAirplaneObj;
}

//创建飞船&与其有关的动画
bool GameAirplaneObj::createAirplane()
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto m_sprite = Sprite::create("airp20.png");//创建精灵－－飞机
    m_sprite->setScale(0.8);//飞机缩放为原大小一半
//    m_sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    //帧动画播放
    Animation* animation = this->createAnimation();
    Animate* animate = Animate::create(animation);
    this->idleAction = RepeatForever::create(animate);
    
    //跳跃动作创建
    ActionInterval *up = CCMoveBy::create(0.4f,Point(0, 8));
    ActionInterval *upBack= up->reverse();
    this->bounceAction = RepeatForever::create(Sequence::create(up, upBack, NULL));
    
    m_sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
    addChild(m_sprite);
    return true;
}

Animation* GameAirplaneObj::createAnimation()
{
    auto animation = Animation::create();
    
    for( int i=20;i<49;i++)
    {
        char szName[100] = {0};
        sprintf(szName, "airp%d.png", i);
        animation->addSpriteFrameWithFile(szName);
    }
    
    animation->setDelayPerUnit(2.8f / 59.0f);
    animation->setRestoreOriginalFrame(true);
    return animation;
}

void GameAirplaneObj::idle()
{
    if (checkState(ACTION_STATE_IDLE)) {
      //  this->runAction(idleAction);
       // this->runAction(swingAction);
    }
}

//飞行器蹦起
void GameAirplaneObj::bounce()
{
    if(checkState(ACTION_STATE_BOUNCE)) {
        this->stopAction(bounceAction);
        this->getPhysicsBody()->setGravityEnable(true);
    }
}

//飞行器无敌加速
void GameAirplaneObj::speedup()
{
}

//飞行器爆炸（结束）
void GameAirplaneObj::explode()
{
    if(checkState(ACTION_STATE_EXPLODE)) {
        this->stopAllActions();
    }
}

bool GameAirplaneObj::checkState(ActionState state)
{
    currentStatus = state;
    return true;
}

void GameAirplaneObj::onExit()
{
    Node::onExit();
}

