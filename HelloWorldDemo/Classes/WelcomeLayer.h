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
    // implement the "static create()" method manually
    CREATE_FUNC(WelcomeLayer);
    
private:
    /**
     * The start button has been pressed will call this function
     */
    void menuStartCallback(Ref *sender);
    void menuHelpCallback(Ref *sender);
    void menuBackCallback(Ref *sender);
    void initUI();
    
private:
    Sprite *helpImg;
    
    Sprite *backButton;
    Sprite *activeBackButton;
    
    Sprite *helpButton;
    Sprite *activeHelpButton;
    
    Sprite *startButton;
    Sprite *activeStartButton;
    
    Node *backNode;
    Node *helpNode;
    Node *startNode;
    
    

    
    //Menu *helpMenu;
   // Menu *startMenu;
   // Menu *backMenu;
    Size visiableSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
};

#endif /* defined(__HelloWorldDemo__WelcomeLayer__) */
