//
//  RocketMonsterObj.h
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/18.
//
//

#ifndef __HelloWorldDemo__RocketMonsterObj__
#define __HelloWorldDemo__RocketMonsterObj__

#include <stdio.h>

#include "GameMonsterObj.h"
#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

//继承抽象类monster衍生出火箭敌人类
class RocketMonsterObj:public GameMonsterObj
{
public:
    RocketMonsterObj(void);
    virtual ~RocketMonsterObj(void);
    virtual void onEnter();
    virtual void onExit();
    
    static RocketMonsterObj* getInstance();
    bool createMonster()const;
protected:
    //static cocos2d::Animation* createAnimation();
private:
    //static BirdMonsterObj* shareBireMonster;
    Sprite* m_sprite;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
};
#endif /* defined(__HelloWorldDemo__RocketMonsterObj__) */
