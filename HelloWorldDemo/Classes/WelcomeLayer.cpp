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
    auto background = Sprite::create("gamebackgrounds11.png");
    background->setAnchorPoint(Vec2(0, 0));
    background->setPosition(origin.x, origin.y);
    this->addChild(background);
    
    
    //开始按钮
    auto startButton = Sprite::create("startBtn.png");
    auto activeStartButton = Sprite::create("startBtn.png");
    
    activeStartButton->setPositionY(5);
    auto startMenuItem  = MenuItemSprite::create(startButton,activeStartButton,NULL,CC_CALLBACK_1(WelcomeLayer::menuStartCallback, this));
//    auto startMenuItem = MenuItemImage::create("UIbutton.png","UIbutton.png",CC_CALLBACK_1(WelcomeLayer::menuStartCallback, this));
    startMenuItem->setPosition(Point(origin.x,origin.y));
    
    auto startMenu = Menu::create(startMenuItem,NULL);
    startMenu->setPosition(Point(origin.x + visiableSize.width/3 ,origin.y + visiableSize.height/3));
    this->addChild(startMenu);
    
    
    //帮助按钮
    Sprite* helpButton = Sprite::create("helpBtn.png");
    Sprite* activeHelpButton = Sprite::create("helpBtn.png");
    
    activeHelpButton->setPositionY(5);
    auto helpMenuItem  = MenuItemSprite::create(helpButton,activeHelpButton,NULL,CC_CALLBACK_1(WelcomeLayer::menuHelpCallback, this));
   // auto helpMenuItem = MenuItemImage::create("UIHelp.png","UIHelp.png",CC_CALLBACK_1(WelcomeLayer::menuHelpCallback, this));
    helpMenuItem->setPosition(Point(origin.x,origin.y));
    
    auto helpMenu = Menu::create(helpMenuItem,NULL);
    helpMenu->setPosition(Point(origin.x + visiableSize.width/2,origin.y + visiableSize.height/3));
    addChild(helpMenu);

    
    //信息按钮
    Sprite* aboutButton = Sprite::create("aboutBtn.png");
    Sprite* activeAboutButton = Sprite::create("aboutBtn.png");
    
    activeAboutButton->setPositionY(5);
    auto aboutMenuItem  = MenuItemSprite::create(aboutButton,activeAboutButton,NULL,CC_CALLBACK_1(WelcomeLayer::menuAboutCallback, this));
    aboutMenuItem->setPosition(Point(origin.x,origin.y));
    
    auto aboutMenu = Menu::create(aboutMenuItem,NULL);
    aboutMenu->setPosition(Point(origin.x + 2*visiableSize.width/3,origin.y + visiableSize.height/3));
    addChild(aboutMenu);
    return true;
}

void WelcomeLayer::onExit()
{
    Node::onExit();
    Layer::onExit();
}

void WelcomeLayer::onEnter()
{
    Node::onEnter();
    Layer::onEnter();
}



void WelcomeLayer::menuStartCallback(Ref *sender){
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.wav");
    auto scene = GameScene::create();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}

void WelcomeLayer::menuHelpCallback(Ref *sender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.wav");
    Point origin = Director::getInstance()->getVisibleOrigin();
    this->helpLayer = HelpLayer::create();
    addChild(helpLayer);
    
    Sprite *backButton = Sprite::create("back.png");
    Sprite *activeBackButton = Sprite::create("back.png");

    auto backMenuItem  = MenuItemSprite::create(backButton,activeBackButton,NULL,CC_CALLBACK_1(WelcomeLayer::menuBackCallback, this));
    backMenuItem->setPosition(Point(origin.x  ,origin.y + 5 ));
    
    backMenu = Menu::create(backMenuItem,NULL);
    backMenu->setPosition(Point(origin.x ,origin.y + 5));
    backMenu->setScale(0.8);
    addChild(backMenu);

}

void WelcomeLayer::menuAboutCallback(Ref *sender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.wav");
    //Point origin = Director::getInstance()->getVisibleOrigin();
    this->aboutLayer = AboutLayer::create();
    this->addChild(aboutLayer);
    
    Sprite *backButton = Sprite::create("backBtn1.png");
    Sprite *activeBackButton = Sprite::create("backBtn1.png");

    auto backMenuItem  = MenuItemSprite::create(backButton,activeBackButton,NULL,CC_CALLBACK_1(WelcomeLayer::menuBackAboutCallback, this));
    backMenuItem->setPosition(Point(10 , 10));
    
    backAboutMenu = Menu::create(backMenuItem,NULL);
    backAboutMenu->setPosition(Point( 10 , 10));
    backAboutMenu->setScale(0.8);
    addChild(backAboutMenu);

}

void WelcomeLayer::menuBackCallback(Ref *sender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.wav");
    removeChild(helpLayer);
    removeChild(backMenu);
}

void WelcomeLayer::menuBackAboutCallback(Ref *sender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.wav");
    removeChild(aboutLayer);
    removeChild(backAboutMenu);
}



