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
    auto background = Sprite::create("gamebackgrounds.png");
    background->setAnchorPoint(Vec2(0, 0));
    background->setPosition(origin.x, origin.y);
    this->addChild(background);
    
    
    //开始按钮
    auto startButton = Sprite::create("UIbutton.png");
    auto activeStartButton = Sprite::create("UIbutton.png");
    
    activeStartButton->setPositionY(5);
    auto startMenuItem  = MenuItemSprite::create(startButton,activeStartButton,NULL,CC_CALLBACK_1(WelcomeLayer::menuStartCallback, this));
//    auto startMenuItem = MenuItemImage::create("UIbutton.png","UIbutton.png",CC_CALLBACK_1(WelcomeLayer::menuStartCallback, this));
    startMenuItem->setPosition(Point(origin.x,origin.y));
    
    auto startMenu = Menu::create(startMenuItem,NULL);
    startMenu->setPosition(Point(origin.x + visiableSize.width/2 - 80 ,origin.y + visiableSize.height/3 -20));
    startMenu->setScale(0.8);
    this->addChild(startMenu);
    
    
    //帮助按钮
    Sprite* helpButton = Sprite::create("UIHelp.png");
    Sprite* activeHelpButton = Sprite::create("UIHelp.png");
    
    activeHelpButton->setPositionY(5);
    auto helpMenuItem  = MenuItemSprite::create(helpButton,activeHelpButton,NULL,CC_CALLBACK_1(WelcomeLayer::menuHelpCallback, this));
   // auto helpMenuItem = MenuItemImage::create("UIHelp.png","UIHelp.png",CC_CALLBACK_1(WelcomeLayer::menuHelpCallback, this));
    helpMenuItem->setPosition(Point(origin.x,origin.y));
    
    auto helpMenu = Menu::create(helpMenuItem,NULL);
    helpMenu->setPosition(Point(origin.x + visiableSize.width/2 - 80,origin.y + visiableSize.height/6 -20));
    helpMenu->setScale(0.8);
    addChild(helpMenu);

 
    return true;
}

void WelcomeLayer::onExit()
{
    Node::onExit();
}

void WelcomeLayer::onEnter()
{
    Node::onEnter();
}



void WelcomeLayer::menuStartCallback(Ref *sender){
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("click.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.wav");
    
    auto scene = GameScene::createScene();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}

void WelcomeLayer::menuHelpCallback(Ref *sender)
{
    
    Point origin = Director::getInstance()->getVisibleOrigin();
    this->helpLayer = HelpLayer::create();
    addChild(helpLayer);
    
    Sprite *backButton = Sprite::create("back.png");
    Sprite *activeBackButton = Sprite::create("back.png");
    //activeBackButton->setPositionY(5);
    //auto backMenuItem = MenuItemImage::create("back.png","back.png",CC_CALLBACK_1(WelcomeLayer::menuBackCallback, this));
    auto backMenuItem  = MenuItemSprite::create(backButton,activeBackButton,NULL,CC_CALLBACK_1(WelcomeLayer::menuBackCallback, this));
    backMenuItem->setPosition(Point(origin.x + 20  ,origin.y + 20 ));
    
    backMenu = Menu::create(backMenuItem,NULL);
    backMenu->setPosition(Point(origin.x + 20 ,origin.y + 20 ));
    backMenu->setScale(0.8);
    addChild(backMenu);
    //this->addChild(this->backNode);
}

void WelcomeLayer::menuBackCallback(Ref *sender)
{
    removeChild(helpLayer);
    removeChild(backMenu);
}


