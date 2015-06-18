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
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto background = Sprite::create("gamebackgrounds.png");
    background->setAnchorPoint(Vec2(0, 0));
    background->setPosition(0, 0);
    this->addChild(background);
    initUI();
    //add the copyright-text to the current scne
//    Sprite *copyright = Sprite::create("brand_copyright");
//    copyright->setPosition(Point(origin.x + visiableSize.width/2, origin.y + visiableSize.height/6));
//    this->addChild(copyright, 10);
    
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

void WelcomeLayer::initUI()
{
    //add the start-menu to the current scene
    Size visiableSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    startNode = Node::create();
    startButton = Sprite::create("UIbutton.png");
    activeStartButton = Sprite::create("UIbutton.png");

    activeStartButton->setPositionY(5);
    auto startMenuItem  = MenuItemSprite::create(startButton,activeStartButton,NULL,CC_CALLBACK_1(WelcomeLayer::menuStartCallback, this));
    startMenuItem->setPosition(Point(origin.x + visiableSize.width/2 ,origin.y + visiableSize.height/3));
    
    auto startMenu = Menu::create(startMenuItem,NULL);
    startMenu->setPosition(Point(origin.x  ,origin.y ));
    startMenu->setScale(0.8);
    startNode->addChild(startMenu);
    this->addChild(startNode);
    
    
    //帮助界面
    helpNode = Node::create();
    helpButton = Sprite::create("UIHelp.png");
    activeHelpButton = Sprite::create("UIHelp.png");
    //background->setAnchorPoint(Vec2(0, 0));
    //background->setPosition(0, 0);
    activeHelpButton->setPositionY(5);
    auto helpMenuItem  = MenuItemSprite::create(helpButton,activeHelpButton,NULL,CC_CALLBACK_1(WelcomeLayer::menuHelpCallback, this));
    helpMenuItem->setPosition(Point(origin.x + visiableSize.width/2 ,origin.y + visiableSize.height/6));
    
    auto helpMenu = Menu::create(helpMenuItem,NULL);
    helpMenu->setPosition(Point(origin.x ,origin.y));
    helpMenu->setScale(0.8);
    helpNode->addChild(helpMenu);
    this->addChild(helpNode);
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
//    removeChild(startMenu);
//    removeChild(helpMenu);
    helpImg = Sprite::create("helpImg.png");
    helpImg->setAnchorPoint(Vec2(0, 0));
    helpImg->setPosition(0, 0);
    this->addChild(this->helpImg);
    
    //add the back-menu to the current scene
    backNode = Node::create();
    backButton = Sprite::create("back.png");
    activeBackButton = Sprite::create("back.png");

    activeBackButton->setPositionY(5);
    auto backMenuItem  = MenuItemSprite::create(backButton,activeBackButton,NULL,CC_CALLBACK_1(WelcomeLayer::menuBackCallback, this));
    backMenuItem->setPosition(Point(origin.x  ,origin.y ));
    
    auto backMenu = Menu::create(backMenuItem,NULL);
    backMenu->setPosition(Point(origin.x + 20 ,origin.y + 20 ));
    backMenu->setScale(0.8);
    backNode->addChild(backMenu);
    this->addChild(this->backNode);
}

void WelcomeLayer::menuBackCallback(Ref *sender)
{
    removeChild(helpImg);
    removeChild(backNode);
    //initUI();
}
