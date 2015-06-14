//
//  GameNumber.h
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/13.
//
//

#ifndef __HelloWorldDemo__GameNumber__
#define __HelloWorldDemo__GameNumber__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class GameNumber:public Layer
{
public:
    GameNumber(void);
    ~GameNumber(void);
    static GameNumber* getInstance();
private:
    static GameNumber* shareNumberObj;
};
#endif /* defined(__HelloWorldDemo__GameNumber__) */
