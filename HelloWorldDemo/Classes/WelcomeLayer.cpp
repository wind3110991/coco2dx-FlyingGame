//
//  WelcomeLayer.cpp
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/15.
//
//

#include "WelcomeLayer.h"

WelcomeLayer::WelcomeLayer(){};

WelcomeLayer::~WelcomeLayer(){};

bool WelcomeLayer::init(){
    if(!Layer::init()){
        return false;
    }
    //get the origin point of the X-Y axis, and the visiable size of the screen
    Size visiableSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto background = CCSprite::create("gamebackgrounds.png");
    background->setAnchorPoint(Vec2(0, 0));
    background->setPosition(0, 0);
    this->addChild(background);
    
    //add the start-menu to the current scene
    Sprite *startButton = Sprite::create("UIbutton.png");
    Sprite *activeStartButton = Sprite::create("UIbutton.png");
    //background->setAnchorPoint(Vec2(0, 0));
    //background->setPosition(0, 0);
    activeStartButton->setPositionY(5);
    auto menuItem  = MenuItemSprite::create(startButton,activeStartButton,NULL,CC_CALLBACK_1(WelcomeLayer::menuStartCallback, this));
    menuItem->setPosition(Point(origin.x + visiableSize.width/2 ,origin.y + visiableSize.height/3));
    
    auto menu = Menu::create(menuItem,NULL);
    menu->setPosition(Point(origin.x ,origin.y));
    menu->setScale(0.8);
    this->addChild(menu,1);
    
    
    //add the copyright-text to the current scne
//    Sprite *copyright = Sprite::create("brand_copyright");
//    copyright->setPosition(Point(origin.x + visiableSize.width/2, origin.y + visiableSize.height/6));
//    this->addChild(copyright, 10);
    
    return true;
}

void WelcomeLayer::menuStartCallback(Ref *sender){
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("click.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.wav");
    
    auto scene = GameScene::createScene();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}
