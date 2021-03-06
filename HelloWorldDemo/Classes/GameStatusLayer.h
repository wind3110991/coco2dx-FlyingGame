//
//  GameStatusLayer.h
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/13.
//
//

#ifndef __HelloWorldDemo__GameStatusLayer__
#define __HelloWorldDemo__GameStatusLayer__

#include <stdio.h>
#include "cocos2d.h"
#include <cstdlib>
#include "GameLayer.h"
#include "GameScene.h"
#include "string.h"
#include "GameOptionLayer.h"

using namespace cocos2d;
using namespace std;


class GameStatusLayer:public Layer,public StatusDelegate
{
public:
    GameStatusLayer(void);
    
    ~GameStatusLayer(void);
    
    virtual bool init();
    
    //void onGameStart();
    
    //void onGamePlaying(int score);
    
    void onGameEnd(int curScore, int bestScore);
    
    CREATE_FUNC(GameStatusLayer);
private:
    void showReadyStatus();
    
    void showStartStatus();
    
    void showOverStatus(int curScore, int bestScore);
    
    void loadWhiteSprite();
    
    void blinkFullScreen();
    
    void fadeInGameOver();
    
    void jumpToScorePanel();
    
    void fadeInRestartBtn();
    
    void refreshScoreCallback();
    
    void refreshScoreExecutor(float dt);
    
    string getMedalsName(int score);
    
    Sprite* blink;
    
    void setBlinkSprite();
    
    void blinkAction();
    
    void menuRestartCallback(Ref *sender);
    
    Sprite* scoreSprite;
    
    Sprite* getreadySprite;
    
    Sprite* tutorialSprite;
    
    Sprite* whiteSprite;
    
    int currentScore;
    
    int bestScore;
    
    int tmpScore;
    
    bool isNewRecord;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
};

#endif /* defined(__HelloWorldDemo__GameStatusLayer__) */
