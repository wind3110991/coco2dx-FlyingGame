//
//  WelcomeLayer.h
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/15.
//
//

#ifndef __HelloWorldDemo__WelcomeLayer__
#define __HelloWorldDemo__WelcomeLayer__

#include <stdio.h>
#include "CCMenuItem.h"
#include "GameScene.h"
#include "HelpLayer.h"
#include "time.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace std;

const int START_BUTTON_TAG = 100;


class WelcomeLayer : public Layer{
public:
    WelcomeLayer(void);
    ~WelcomeLayer(void);
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    Menu *backMenu;
    // implement the "static create()" method manually
    CREATE_FUNC(WelcomeLayer);
    
private:
    /**
     * The start button has been pressed will call this function
     */
    void menuStartCallback(Ref *sender);
    void menuHelpCallback(Ref *sender);
    void menuBackCallback(Ref *sender);
    
private:
    Sprite *helpImg;
    Layer* helpLayer;
    
};

#endif /* defined(__HelloWorldDemo__WelcomeLayer__) */
