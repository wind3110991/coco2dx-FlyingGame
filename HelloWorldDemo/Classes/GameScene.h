//
//  GameScene.h
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/9.
//
//

#ifndef __HelloWorldDemo__GameScene__
#define __HelloWorldDemo__GameScene__

#include <stdio.h>
#include "cocos2d.h"
#include "sys/socket.h"
#include "GameBackgroundLayer.h"
#include "GameAirplaneObj.h"

using namespace cocos2d;
using namespace std;

const int AIRPLANE_RADIUS = 30;

class GameAirplaneObj;
class GameScene:public Scene
{
public:
    GameScene(void);
    ~GameScene(void);
   
    static Scene *createScene();
    
    void setover();
    void setPhyWorld(PhysicsWorld* world){m_world = world;}
    virtual bool init() override;
    CREATE_FUNC(GameScene);

    bool isover;
private:
    // 定时器，每一帧调用
    virtual void update(float delta) override;
    
    // 此场景加载完毕后的操作
    virtual void onEnterTransitionDidFinish() override;
    
private:
    GameAirplaneObj *airplane;
    
    PhysicsWorld *m_world;
    // 游戏背景
    GameBackgroundLayer *gamebackgroundLayer;
    
    Sprite* gameover;
};


#endif /* defined(__HelloWorldDemo__GameScene__) */
