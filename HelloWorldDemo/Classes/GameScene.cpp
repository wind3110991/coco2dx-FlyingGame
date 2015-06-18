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


//创建一个带物理引擎的场景
Scene *GameScene::createScene()
{
    auto scene = Scene::createWithPhysics();
   // scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, -900));
//    
    auto layer = GameScene::create();
    //layer->setPhyWorld(scene->getPhysicsWorld()); //工厂模式方法实例化物理世界
    scene->addChild(layer);

//为场景创建物理边界
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode1 = Node::create();
    auto edgeNode2 = Node::create();
    Point p1 = {0, 0};
    Point p2 = {visibleSize.width,0};
    Point p3 = {0, visibleSize.height};
    Point p4 = {visibleSize.width,visibleSize.height};
    
    auto linebody1 = PhysicsBody::createEdgeSegment(p1, p2);
    auto linebody2 = PhysicsBody::createEdgeSegment(p3, p4);
    //edgeNode->setPosition(Point(visibleSize.width/2 ,visibleSize.height/2));
    edgeNode1->setPhysicsBody(linebody1);
    edgeNode2->setPhysicsBody(linebody2);
    
    scene->addChild(edgeNode1);
    scene->addChild(edgeNode2);

    return scene;
}

bool GameScene::init()
{
    if(!Scene::initWithPhysics())
    {
        return false;
    }
    
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("bgm.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm.mp3");
    // 加载背景地图
    this->gamebackgroundLayer = GameBackgroundLayer::create();
    this->gamebackgroundLayer->setAnchorPoint(Vec2::ZERO);
    this->gamebackgroundLayer->setPosition(Vec2::ZERO);
    this->addChild(gamebackgroundLayer);
    //创建状态层
    auto statusLayer = GameStatusLayer::create();
    
    //创建游戏层
    auto gameLayer = GameLayer::create();
    if(gameLayer) {
        gameLayer->setPhyWorld(this->getPhysicsWorld());
        gameLayer->setDelegator(statusLayer);
        this->addChild(gameLayer);
    }
    
    if(statusLayer) {
        this->addChild(statusLayer);
    }
    
    //创建控制层
    auto optionLayer = GameOptionLayer::create();
    if(optionLayer) {
        optionLayer->setDelegator(gameLayer);
        this->addChild(optionLayer);
    }
    return true;
}

void GameScene::updateSpeed(float dt)
{
    this->gamebackgroundLayer->scrollSpeedUp();
}


void GameScene::onEnterTransitionDidFinish()
{
    Node::onEnterTransitionDidFinish();
    // 场景加载完毕才滚动背景
    //this->schedule(schedule_selector(GameScene::updateSpeed), 2.0f, kRepeatForever, 1.0f);
    this->scheduleUpdate();
}

void GameScene::update(float delta)
{
    this->gamebackgroundLayer->scrollBackground();
    //this->gamebackgroundLayer->scrollSpeedUp();
}

void GameScene::restart() {
    this->removeAllChildren();
    //this->createScene();
    this->init();
}

