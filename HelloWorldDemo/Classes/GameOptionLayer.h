//
//  GameOptionLayer.h
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/13.
//
//

#ifndef __HelloWorldDemo__GameOptionLayer__
#define __HelloWorldDemo__GameOptionLayer__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class OptionDelegate
{
public:
    virtual void onTouch() = 0;
};

class GameOptionLayer:public Layer
{
public:
    GameOptionLayer();
    ~GameOptionLayer();
    
    virtual bool init();
    CREATE_FUNC(GameOptionLayer);
    
    // override
    void onTouchesBegan(const std::vector<Touch*>& touches, Event *event);
    
    CC_SYNTHESIZE(OptionDelegate*, delegator, Delegator);
};

#endif /* defined(__HelloWorldDemo__GameOptionLayer__) */
