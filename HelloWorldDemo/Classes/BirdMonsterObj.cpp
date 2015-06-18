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

void BirdMonsterObj::onEnter()
{
    Node::onEnter();
    
    m_sprite = Sprite::create("birdmonster1.png");
    m_sprite->setScale(0.8);
    Animation* animation = this->createAnimation();
    m_sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
    addChild(m_sprite);
}
void BirdMonsterObj::onExit()
{
    Node::onExit();
    removeChild(this->m_sprite);
}

//BirdMonsterObj* BirdMonsterObj::shareBireMonster = nullptr;

BirdMonsterObj* BirdMonsterObj::getInstance()
{

    BirdMonsterObj* bireMonster = new BirdMonsterObj();
    return bireMonster;
}

bool BirdMonsterObj::createMonster()const
{
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