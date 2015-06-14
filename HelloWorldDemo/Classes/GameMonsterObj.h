//
//  GameMonsterObj.h
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/10.
//
//

#ifndef __HelloWorldDemo__GameMonsterObj__
#define __HelloWorldDemo__GameMonsterObj__

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;

const int MONSTER_DISTANCE = 100;

const int MONSTER_POSITION_Y = 300;

class GameMonsterObj:public Node
{
public:
    GameMonsterObj(void);
    virtual ~GameMonsterObj(void);
    
    bool createMonster();
    int getRandomHeight();
    int getRandomDistance();
private:
    
};

#endif /* defined(__HelloWorldDemo__GameMonsterObj__) */
