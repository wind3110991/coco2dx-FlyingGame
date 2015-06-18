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

const int ROTATE_INTERVAL = 1;

const int ROTATE_DEGREE = 720;

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
    virtual void onEnter();
    virtual void onExit();
    Sprite* m_sprite;
    
    void idle();
    void bounce();
    void speedup();
    void die();

protected:
    static cocos2d::Animation* createAnimation();
private:
    bool checkState(ActionState state); //设置当前飞机状态
private:
    static GameAirplaneObj* shareAirplaneObj;
    unsigned int isFirstTime;
    
    Action* idleAction;
    Action* bounceAction;
    Action* dieAction;
    ActionState currentStatus;
    
};
#endif /* defined(__HelloWorldDemo__GameAirplaneObj__) */
