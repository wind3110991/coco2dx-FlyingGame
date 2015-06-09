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

// 游戏背景层
class GameBackgroundLayer : public cocos2d::Layer
{
public:
    GameBackgroundLayer(void);
    ~GameBackgroundLayer(void);
    
    virtual bool init() override;
    CREATE_FUNC(GameBackgroundLayer);
    
    // 滚动卷轴地图
    void scrollBackground();
    
private:
    // 初始化背景地图
    void initBackground();
    
private:
    // 背景地图
    cocos2d::Sprite *background_1;
    cocos2d::Sprite *background_2;
    
    // 沿X轴滚动速度
    double speedX;
};

#endif /* defined(__HelloWorldDemo__GameBackgroundLayer__) */
