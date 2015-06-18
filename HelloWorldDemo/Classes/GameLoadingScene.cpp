//
//  GameLoadingScene.cpp
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/15.
//
//

#include "GameLoadingScene.h"

LoadingScene::LoadingScene(){}

LoadingScene::~LoadingScene(){}

bool LoadingScene::init() {
    if(Scene::init()){
        return true;
    } else {
        return false;
    }
}

void LoadingScene::onEnter(){
    // add background to current scene
    Sprite *background = Sprite::create("LoadingPage1.png");
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    background->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
    this->addChild(background);
    this->loadingCallBack();
}

void LoadingScene::loadingCallBack(){
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("crash.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("bounce.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("error.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("stop.wav");
    // After load all the things, change the scene to new one
    //auto scene = HelloWorld::createScene();
    auto scene = WelcomeScene::create();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}