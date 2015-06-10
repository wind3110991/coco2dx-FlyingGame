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

//void GameAirplaneObj::initGameAirplane()
//{
//    
//    Size visibleSize = Director::getInstance()->getVisibleSize();
//    Vec2 origin = Director::getInstance()->getVisibleOrigin();
//    auto sprite = Sprite::create("air1.png");//创建精灵－－飞机
//    sprite->setScale(0.5);//飞机缩放为原大小一半
//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//    this->addChild(sprite, 0);
//    
//    auto animation = Animation::create();
//    
//    for( int i=1;i<49;i++)
//    {
//        char szName[100] = {0};
//        sprintf(szName, "air%d.png", i);
//        animation->addSpriteFrameWithFile(szName);
//    }
//    
//    animation->setDelayPerUnit(2.8f / 59.0f);
//    animation->setRestoreOriginalFrame(true);
//    
//    sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
//
//}

void GameAirplaneObj::setState(short var)
{
    if(state == var)
        return;
    state = var;
    switch(state){
        case 1://跳起
//            this->stopAllActions();
//            m_sprite->stopAllActions();
//            m_sprite->setTexture(jump);
//            this->runAction(CCSequence::create(CCJumpBy::create(2.5,Point(0,0),100,1),CCCallFunc::create(this, callfunc_selector(GameAirplaneObj::jumpend)),NULL));
            break;
//        case 2://加速
//            this->stopAllActions();
//            m_sprite->stopAllActions();
//            m_sprite->setTexture(hurt);
//            this->runAction(CCSequence::create(CCBlink::create(3, 10),CCCallFunc::create(this, callfunc_selector(GameAirplaneObj::speedend)),NULL));
//            ((GameMain *)this->getParent())->setover();
        case 0://正常运行状态
            auto animation = Animation::create();
            
            for( int i=1;i<49;i++)
            {
                char szName[100] = {0};
                sprintf(szName, "air%d.png", i);
                animation->addSpriteFrameWithFile(szName);
            }
            
            animation->setDelayPerUnit(2.8f / 59.0f);
            animation->setRestoreOriginalFrame(true);
            m_sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
            break;
    }
}

void GameAirplaneObj::onEnter()
{
    
    Node::onEnter();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto m_sprite = Sprite::create("air1.png");//创建精灵－－飞机
    m_sprite->setScale(0.5);//飞机缩放为原大小一半
    m_sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    //帧动画播放
    auto animation = Animation::create();
    
    for( int i=20;i<49;i++)
    {
        char szName[100] = {0};
        sprintf(szName, "air%d.png", i);
        animation->addSpriteFrameWithFile(szName);
    }
    
    animation->setDelayPerUnit(2.8f / 59.0f);
    animation->setRestoreOriginalFrame(true);
    
    m_sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
    state = 0;
    
    addChild(m_sprite);
}


void GameAirplaneObj::onExit()
{
    Node::onExit();
}

void GameAirplaneObj::jumpend()
{
    
    setState(1);
}

//bool containsTouchLocation(Touch* touch)
//{
//    return rect().containsPoint(convertTouchToNodeSpaceAR(touch));
//}
bool GameAirplaneObj::onTouchBegan(Touch* touch, Event* event)
{
    if(((GameScene *)this->getParent())->isover)
        return false;
    //设置运动状态
    setState(0);
    return true;
}

void GameAirplaneObj::onTouchMoved(Touch* touch, Event* event)
{

}

void GameAirplaneObj::onTouchEnded(Touch* touch, Event* event)
{

}

//void GameAirplaneObj::touchDelegateRetain()
//{
//    this->retain();
//}
//
//void GameAirplaneObj::touchDelegateRelease()
//{
//    this->release();
//}

//void GameAirplaneObj::addNewSpriteAtPosition(Point p)
//{
//    auto sprite = Sprite::create("air1.png");
//    sprite->setTag(1);
//    auto body = PhysicsBody::createCircle(sprite->getContentSize().width / 2);
//    sprite->setPhysicsBody(body);
//    sprite->setPosition(p);
//    this->addChild(sprite);
//}