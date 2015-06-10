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
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    auto layer = GameScene::create();
    layer->setPhyWorld(scene->getPhysicsWorld()); //工厂模式方法实例化物理世界
    
    scene->addChild(layer);
    
//为场景创建物理边界
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
    edgeNode->setPhysicsBody(body);
    scene->addChild(edgeNode);
    
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
    
//实例化飞机
    GameAirplaneObj* airplane1 = new GameAirplaneObj();
    addChild(airplane1,0);
    
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

void GameScene::setover()
{
    Menu* pMenu = (Menu *)this->getChildByTag(25);
    pMenu->setVisible(true);
    pMenu->setEnabled(true);
    gameover->setVisible(true);
    gameover->setScale(0);
    pMenu->setScale(0);
    pMenu->runAction(CCScaleTo::create(0.5,1));
    gameover->runAction(CCScaleTo::create(0.5,0.5));
    isover = true;

}