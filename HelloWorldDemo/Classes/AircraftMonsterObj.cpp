//
//  AircraftMonsterObj.cpp
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/18.
//
//

#include "AircraftMonsterObj.h"

AircraftMonsterObj::AircraftMonsterObj(void)
{
}

AircraftMonsterObj::~AircraftMonsterObj(void)
{
    
}

void AircraftMonsterObj::onEnter()
{
    Node::onEnter();
    
    m_sprite = Sprite::create("aircraft.png");
    m_sprite->setScale(0.8);
    addChild(m_sprite);
}
void AircraftMonsterObj::onExit()
{
    Node::onExit();
    removeChild(this->m_sprite);
}


bool AircraftMonsterObj::createMonster()const
{
    return true;
}
