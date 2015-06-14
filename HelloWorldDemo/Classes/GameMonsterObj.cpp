//
//  GameMonsterObj.cpp
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/10.
//
//

#include "GameMonsterObj.h"

GameMonsterObj::GameMonsterObj(void)
{
}

GameMonsterObj::~GameMonsterObj(void)
{
}

bool GameMonsterObj::createMonster()
{
    
    return true;
}

int GameMonsterObj::getRandomHeight() {
    Size visibleSize = Director::getInstance()->getVisibleSize();
    return rand()%(int)(2*MONSTER_POSITION_Y + MONSTER_DISTANCE - visibleSize.height);
}

int GameMonsterObj::getRandomDistance()
{
    return rand()%(int)getRandomHeight();
}