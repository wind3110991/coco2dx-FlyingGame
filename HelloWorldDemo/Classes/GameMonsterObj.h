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

class GameMonsterObj:public Node
{
public:
    GameMonsterObj(void);
    virtual ~GameMonsterObj(void);
    virtual void onEnter();
    virtual void onExit();
    bool _visable;
    void set_visable(bool var);
    bool get_visable();
};

#endif /* defined(__HelloWorldDemo__GameMonsterObj__) */
