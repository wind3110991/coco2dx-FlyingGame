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

using namespace std;
using namespace cocos2d;

const int BIRMONSTER_RADIUS = 40;

//继承抽象类monster衍生出猫头鹰敌人类
class BirdMonsterObj:public GameMonsterObj
{
public:
    BirdMonsterObj(void);
    virtual ~BirdMonsterObj(void);
    virtual void onEnter();
    virtual void onExit();
    
//    static BirdMonsterObj* getInstance();
    bool createMonster()const;
protected:
    static cocos2d::Animation* createAnimation();
private:
    //static BirdMonsterObj* shareBireMonster;
    Sprite* m_sprite;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
};
#endif /* defined(__HelloWorldDemo__BirdMonsterObj__) */