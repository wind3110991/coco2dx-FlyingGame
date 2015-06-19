//
//  AircraftMonsterObj.h
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/18.
//
//

#ifndef __HelloWorldDemo__AircraftMonsterObj__
#define __HelloWorldDemo__AircraftMonsterObj__

#include <stdio.h>
#include "GameMonsterObj.h"
#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

const int AIRCRAFTMONSTER_RADIUS = 40;

//继承抽象类monster衍生出飞行器敌人类
class AircraftMonsterObj:public GameMonsterObj
{
public:
    AircraftMonsterObj(void);
    virtual ~AircraftMonsterObj(void);
    virtual void onEnter();
    virtual void onExit();
    
    //    static BirdMonsterObj* getInstance();
    bool createMonster()const;
private:
    //static BirdMonsterObj* shareBireMonster;
    Sprite* m_sprite;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
};

#endif /* defined(__HelloWorldDemo__AircraftMonsterObj__) */
