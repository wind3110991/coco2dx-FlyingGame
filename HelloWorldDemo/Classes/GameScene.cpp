//
//  GameScene.cpp
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/9.
//
//

#include "GameScene.h"

USING_NS_CC;

GameScene::GameScene(void)
{
}


GameScene::~GameScene(void)
{
}

Scene *GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool GameScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    // 加载背景地图
    this->gamebackgroundLayer = GameBackgroundLayer::create();
    this->gamebackgroundLayer->setAnchorPoint(Vec2::ZERO);
    this->gamebackgroundLayer->setPosition(Vec2::ZERO);
    this->addChild(gamebackgroundLayer);
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
/*测试飞机end*/
    
    auto sprite = Sprite::create("air1.png");//创建精灵－－飞机
    sprite->setScale(0.5);//飞机缩放为原大小一半
    
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);
   
    //帧动画播放
    auto animation = Animation::create();
    
    for( int i=1;i<49;i++)
    {
        char szName[100] = {0};
        sprintf(szName, "air%d.png", i);
        animation->addSpriteFrameWithFile(szName);
    }
    
    animation->setDelayPerUnit(2.8f / 59.0f);
    animation->setRestoreOriginalFrame(true);
    
    sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
    
/*测试飞机end*/
    
    return true;
}

void GameScene::onEnterTransitionDidFinish()
{
    Node::onEnterTransitionDidFinish();
    
    // 场景加载完毕才滚动背景
    this->scheduleUpdate();
}

void GameScene::update(float delta)
{
    this->gamebackgroundLayer->scrollBackground();
}