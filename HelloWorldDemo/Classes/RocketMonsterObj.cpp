//
//  RocketMonsterObj.cpp
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/18.
//
//

#include "RocketMonsterObj.h"

RocketMonsterObj::RocketMonsterObj()
{}

RocketMonsterObj::~RocketMonsterObj()
{}

void RocketMonsterObj::onEnter()
{
    Node::onEnter();
    
    m_sprite = Sprite::create("rocket.png");
    m_sprite->setScale(0.8);
    addChild(m_sprite);
}
void RocketMonsterObj::onExit()
{
    Node::onExit();
    removeChild(this->m_sprite);
}

//RocketMonsterObj* RocketMonsterObj::shareBireMonster = nullptr;

RocketMonsterObj* RocketMonsterObj::getInstance()
{
    RocketMonsterObj* rocketMonster = new RocketMonsterObj();
    return rocketMonster;
}

bool RocketMonsterObj::createMonster()const
{
    return true;
}