//
//  WelcomeScene.h
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/15.
//
//

#ifndef __HelloWorldDemo__WelcomeScene__
#define __HelloWorldDemo__WelcomeScene__

#include <stdio.h>
#include "cocos2d.h"
#include "WelcomeLayer.h"
#include "CCMenuItem.h"

using namespace cocos2d;
using namespace std;

class WelcomeScene : public Scene{
public:
    WelcomeScene(void);
    ~WelcomeScene(void);
    bool virtual init();
    CREATE_FUNC(WelcomeScene);
};

#endif /* defined(__HelloWorldDemo__WelcomeScene__) */
