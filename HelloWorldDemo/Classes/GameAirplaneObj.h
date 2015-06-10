//
//  GameAirplaneObj.h
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/9.
//
//

#ifndef __HelloWorldDemo__GameAirplaneObj__
#define __HelloWorldDemo__GameAirplaneObj__

#include <stdio.h>
#include "cocos2d.h"
#include "GameScene.h"

using namespace cocos2d;

class GameAirplaneObj:public Node, public EventListenerTouchOneByOne{
public:
    GameAirplaneObj(void);
    virtual ~GameAirplaneObj(void);
    virtual void onEnter();
    virtual void onExit();
    Sprite* m_sprite;
    //void initGameAirplane(); //初始化飞行器
    
    void jumpend();
    void speedend();
    void setState(short var); //设置当前飞机状态
    //void addNewSpriteAtPosition(Point p);
    
    bool containsTouchLocation(Touch* touch);
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    
//    virtual void touchDelegateRetain();
//    virtual void touchDelegateRelease();
private:
    Texture2D *hurt;
    Texture2D *jump;
    short state;
    bool iscontrol;
};
#endif /* defined(__HelloWorldDemo__GameAirplaneObj__) */
