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

using namespace cocos2d;

typedef enum{
    ACTION_STATE_IDLE,
    ACTION_STATE_BOUNCE,
    ACTION_STATE_EXPLODE
} ActionState;

class GameAirplaneObj:public Node, public EventListenerTouchOneByOne{
public:
    GameAirplaneObj(void);
    virtual ~GameAirplaneObj(void);
    bool init();
    
    static GameAirplaneObj* getInstance();
    bool createAirplane();
    virtual void onExit();
    Sprite* m_sprite;
    //void initGameAirplane(); //初始化飞行器
    
    void idle();
    void bounce();
    void speedup();
    void explode();
    
    //void addNewSpriteAtPosition(Point p);
    
    bool containsTouchLocation(Touch* touch);
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    
//    virtual void touchDelegateRetain();
//    virtual void touchDelegateRelease();
protected:
    static cocos2d::Animation* createAnimation();
private:
    bool setState(ActionState state); //设置当前飞机状态
private:
    static GameAirplaneObj* shareAirplaneObj;
    unsigned int isFirstTime;
    
    Action* idleAction;
    Action* bounceAction;
    ActionState currentStatus;
    
    Texture2D *hurt;
    Texture2D *jump;
    short state;
    bool iscontrol;
};
#endif /* defined(__HelloWorldDemo__GameAirplaneObj__) */
