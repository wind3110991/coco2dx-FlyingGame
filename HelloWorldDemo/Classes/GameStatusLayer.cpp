//
//  GameStatusLayer.cpp
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/13.
//
//

#include "GameStatusLayer.h"

GameStatusLayer::GameStatusLayer(void)
{}

GameStatusLayer::~GameStatusLayer(void)
{}

bool GameStatusLayer::init(){
    if(!Layer::init()){
        return false;
    }
    // init numbers
    this->bestScore = 0;
    this->currentScore = 0;
    this->isNewRecord = false;

   // this->showReadyStatus();
   // this->loadWhiteSprite();
    return true;
}

void GameStatusLayer::onGameEnd(int curScore, int bestScore){
    //this->showOverStatus(curScore,bestScore);
    this->fadeInRestartBtn();
}

void GameStatusLayer::fadeInRestartBtn(){
    Node * tmpNode = Node::create();
    
    //create the restart menu;
    Sprite* restartBtn = Sprite::create("UIRestart.png");
    Sprite* restartBtnActive = Sprite::create("UIRestart.png");
    restartBtnActive->setPositionY(5);
    auto  menuItem = MenuItemSprite::create(restartBtn,restartBtnActive,NULL,CC_CALLBACK_1(GameStatusLayer::menuRestartCallback,this));
    auto menu = Menu::create(menuItem,NULL);
    menu->setPosition(Point(origin.x + visibleSize.width/2 ,origin.y + visibleSize.height/3));
    tmpNode->addChild(menu);
    addChild(tmpNode);
    
    //fade in the two buttons
    auto fadeIn = FadeIn::create(0.1f);
    //tmpNode->stopAllActions();
    //tmpNode->runAction(fadeIn);
    
    CallFunc *actionDone = CallFunc::create(bind(&GameStatusLayer::refreshScoreCallback,this));
    auto sequence = Sequence::createWithTwoActions(fadeIn,actionDone);
    tmpNode->stopAllActions();
    tmpNode->runAction(sequence);
}

void GameStatusLayer::menuRestartCallback(Ref* pSender){
    //SimpleAudioEngine::getInstance()->playEffect("sfx_swooshing.ogg");
    auto scene = GameScene::createScene();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}


void GameStatusLayer::refreshScoreCallback(){
    this->tmpScore = 0;
}

void GameStatusLayer::refreshScoreExecutor(float dt)
{

}