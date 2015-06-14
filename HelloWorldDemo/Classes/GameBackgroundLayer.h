//
//  GameBackgroundLayer.h
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/9.
//
//

#ifndef __HelloWorldDemo__GameBackgroundLayer__
#define __HelloWorldDemo__GameBackgroundLayer__

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;

const int BIRMONSTER_RADIUS = 50;

// 游戏背景层
class GameBackgroundLayer : public Layer
{
public:
    GameBackgroundLayer(void);
    ~GameBackgroundLayer(void);
    
    virtual bool init() override;
    CREATE_FUNC(GameBackgroundLayer);
    
    // 滚动卷轴地图
    void scrollBackground();
    
protected:
    static cocos2d::Animation* createAnimation();
private:
    // 初始化背景地图
    void initBackground();
    
private:
    // 背景地图
    Sprite *background_1;
    Sprite *background_2;
    Sprite *testMonster1;
    Sprite *testMonster2;
    // 沿X轴滚动速度
    Action* idleAction1;
    Action* idleAction2;
    double speedX;
};

#endif /* defined(__HelloWorldDemo__GameBackgroundLayer__) */
