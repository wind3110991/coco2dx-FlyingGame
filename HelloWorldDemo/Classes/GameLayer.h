//
//  GameLayer.h
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/13.
//
//

#ifndef __HelloWorldDemo__GameLayer__
#define __HelloWorldDemo__GameLayer__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"
#include "GameBackgroundLayer.h"
#include "GameAirplaneObj.h"
#include "GameOptionLayer.h"
#include "SimpleAudioEngine.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;
using namespace CocosDenshion;

const int AIRPLANE_RADIUS = 38;

typedef enum _game_status {
    GAME_STATUS_READY = 1,
    GAME_STATUS_PAUSE,
    GAME_STATUS_START,
    GAME_STATUS_OVER
} GameStatus;

class StatusDelegate {
public:

    virtual void onGameEnd(int curSocre, int bestScore) = 0;
};


class GameLayer:public Layer,public OptionDelegate
{
public:
    GameLayer();
    
    ~GameLayer();
    bool virtual init();
    
    CREATE_FUNC(GameLayer);
    CC_SYNTHESIZE(StatusDelegate*, delegator, Delegator);
    void onTouch();
    void setover();

    void setPhyWorld(PhysicsWorld* world){this->m_world = world;}
    
    void update(float delta) override;
    
    void updateScore();
    
    bool isNewHighScore();
    
    void onEnter();
    
    void onExit();
    
    bool onContactBegin(const PhysicsContact& contact);
private:    
    
    void gameStart();
    
    void gameOver();
    
    bool checkHit();
    
    void insertGameOver();
    
    void gameOverInformer(float dt);
    
    void fadeInMenuResume();
    
    void initPauseMenu();
    
    void menuPauseCallback(Ref* pSender);
    
    void menuResumeCallback(Ref* psender);
    
private:
    Sprite* pauseBtn;
    Sprite* pauseBtnActive;
    
    Label *scoreLabel;
    Label *highScoreLabel;
    
    
    Label *label1;
    Label *label2;
    Label *label3;
    
    Node *resumeNode;
    Node *pauseNode;
    
    int score = 0;
    int bestScore = 0;
    
    GameAirplaneObj *airplane;
    PhysicsBody *airplane_body;

    PhysicsWorld *m_world;
    
    GameStatus gameStatus;
    
    Sprite* gameover;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
};

#endif /* defined(__HelloWorldDemo__GameLayer__) */
