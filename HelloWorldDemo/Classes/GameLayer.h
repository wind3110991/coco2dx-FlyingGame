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

const int AIRPLANE_RADIUS = 38;

typedef enum _game_status {
    GAME_STATUS_READY = 1,
    GAME_STATUS_START,
    GAME_STATUS_OVER
} GameStatus;

class StatusDelegate {
public:
    /**
     * When the game start, this method will be called
     */
    //virtual void onGameStart(void) = 0;
    
    /**
     * During paying, after the score changed, this method will be called
     */
    //virtual void onGamePlaying(int score) = 0;
    
    /**
     * When game is over, this method will be called
     */
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
    /**
     * This layer need physical engine work
     */
    void setPhyWorld(PhysicsWorld* world){this->m_world = world;}
    
    void update(float delta) override;
    
    void updateScore();
    
    void onEnter();
    
    
private:    
    bool onContactBegin(const PhysicsContact& contact);
    
    void gameStart();
    
    void gameOver();
    
    bool checkHit();
    
private:
    Label *scoreLabel;
    
    int score = 0;
    
    int bestScore = 0;
    
    GameAirplaneObj *airplane;
    
    PhysicsWorld *m_world;
    
    GameStatus gameStatus;
    
    Sprite* gameover;
    
};

#endif /* defined(__HelloWorldDemo__GameLayer__) */
