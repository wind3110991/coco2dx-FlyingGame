//
//  BirdMonsterObj.cpp
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/15.
//
//

#include "BirdMonsterObj.h"

BirdMonsterObj::BirdMonsterObj(void)
{
}

BirdMonsterObj::~BirdMonsterObj(void)
{
}

//BirdMonsterObj* BirdMonsterObj::shareBireMonster = nullptr;
BirdMonsterObj* BirdMonsterObj::getInstance()
{
//    if(shareBireMonster == NULL){
//        shareBireMonster = new BirdMonsterObj();
//        if(!shareBireMonster->init()){
//            delete(shareBireMonster);
//            shareBireMonster = NULL;
//            CCLOG("ERROR: Could not init shareBireMonster");
//        }
//    }
    BirdMonsterObj* bireMonster = new BirdMonsterObj();
    return bireMonster;
}

bool BirdMonsterObj::createMonster()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto m_sprite = Sprite::create("birdmonster1.png");//创建精灵
    m_sprite->setScale(0.8);
    //m_sprite->setPosition(visibleSize.width/2 + rand()%11*20, visibleSize.height/2 + rand()%11*20);
    
    Animation* animation = this->createAnimation();
    m_sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
    addChild(m_sprite);
    
    return true;
}

Animation* BirdMonsterObj::createAnimation()
{
    auto animation = Animation::create();
    
    for( int i=1;i<26;i++)
    {
        char szName[100] = {0};
        sprintf(szName, "birdmonster%d.png", i);
        animation->addSpriteFrameWithFile(szName);
    }
    
    animation->setDelayPerUnit(2.8f / 59.0f);
    animation->setRestoreOriginalFrame(true);
    return animation;
}