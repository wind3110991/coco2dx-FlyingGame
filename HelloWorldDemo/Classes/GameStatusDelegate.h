//
//  StatusDelegate.h
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/13.
//
//

#ifndef __HelloWorldDemo__StatusDelegate__
#define __HelloWorldDemo__StatusDelegate__

#include <stdio.h>

//抽象类游戏状态
class GameStatusDelegate {
public:
    /**
     * When the game start, this method will be called
     */
    virtual void onGameStart(void) = 0;
    
    /**
     * During paying, after the score changed, this method will be called
     */
    virtual void onGamePlaying(int score) = 0;
    
    /**
     * When game is over, this method will be called
     */
    virtual void onGameEnd(int curSocre, int bestScore) = 0;
};

#endif /* defined(__HelloWorldDemo__StatusDelegate__) */
