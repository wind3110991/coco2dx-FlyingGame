//
//  BirdMonsterObj.h
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/15.
//
//

#ifndef __HelloWorldDemo__BirdMonsterObj__
#define __HelloWorldDemo__BirdMonsterObj__

#include <stdio.h>
#include "GameMonsterObj.h"
#include "cocos2d.h"
#endif /* defined(__HelloWorldDemo__BirdMonsterObj__) */

class BirdMonsterObj:public GameMonsterObj
{
public:
    BirdMonsterObj(void);
    virtual ~BirdMonsterObj(void);
    static BirdMonsterObj* getInstance();
    bool createMonster();
    Sprite* m_sprite;
protected:
    static cocos2d::Animation* createAnimation();
};