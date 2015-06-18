//
//  GameLayer.cpp
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/13.
//
//

#include "GameLayer.h"
#include "stdlib.h"

GameLayer::GameLayer()
{
    
}
GameLayer::~GameLayer()
{
    
}

bool GameLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    gameStatus = GAME_STATUS_READY;
    this->score = 0;//重置分数
    
    this->label1 = Label::createWithTTF("Your Score: ","fonts/Marker Felt.ttf", 24);
    this->label1->setPosition(Vec2(origin.x + visibleSize.width/10,origin.y + visibleSize.height - label1->getContentSize().height));
    this->addChild(label1);
    
    ostringstream  ostr;
    ostr << this->score;
    string str(ostr.str());
    
    this->scoreLabel = Label::create(str,"fonts/Marker Felt.ttf", 24);
    this->scoreLabel->setVisible(true); //计分开始
    scoreLabel->setPosition(Vec2(origin.x + visibleSize.width/6 + 20 ,origin.y + visibleSize.height - label1->getContentSize().height));
    this->addChild(scoreLabel);
    
    //加载暂停按钮
    this->initPauseMenu();

    
    //实例化飞机
    
    this->airplane = GameAirplaneObj::getInstance();
    this->airplane->createAirplane();
    //airplane::create("airp20.png");//创建精灵－－飞机
    //m_sprite->setScale(0.8);//飞机缩放为原大小一半

    this->airplane->setScale(0.8);
    this->airplane->setPosition(Vec2(visibleSize.width/4 + origin.x, visibleSize.height/2 + origin.y));
    
    airplane_body = PhysicsBody::create();
    airplane_body->addShape(PhysicsShapeCircle::create(AIRPLANE_RADIUS));
    airplane_body->setDynamic(true);
    airplane_body->setLinearDamping(0.0f);
    airplane_body->setGravityEnable(true);
    airplane_body->setCategoryBitmask(0x0000000F);
    airplane_body->setContactTestBitmask(0x00000007);
    airplane_body->setMass(0);
    this->airplane->setPhysicsBody(airplane_body);
    
    this->airplane->idle();
    this->airplane->removeFromParent();
    this->addChild(airplane,0);
    //this->schedule(schedule_selector(GameBackgroundLayer::scrollSpeedUp), 1.0f, kRepeatForever, 1.0f);
    this->scheduleUpdate();

    return true;
}

void GameLayer::initPauseMenu()
{
    //加载暂停按钮
    pauseNode = Node::create();
    Sprite* pauseBtn = Sprite::create("UIButtonPause.png");
    Sprite* pauseBtnActive = Sprite::create("UIButtonPause.png");
    pauseBtnActive->setPositionY(5);
    auto  menuItem = MenuItemSprite::create(pauseBtn,pauseBtnActive,NULL,CC_CALLBACK_1(GameLayer::menuPauseCallback,this));
    auto menu = Menu::create(menuItem,NULL);
    menu->setPosition(Point(origin.x + visibleSize.width - 150 ,origin.y + visibleSize.height - 80));
    menu->setScale(0.8);
    pauseNode->addChild(menu);
    addChild(pauseNode);
    
    //fade in the two buttons
    auto fadeIn = FadeIn::create(3.0f);
    //tmpNode->stopAllActions();
    pauseNode->runAction(fadeIn);
    
    auto sequence = Sequence::create(fadeIn, this, NULL);
    pauseNode->stopAllActions();
    pauseNode->runAction(sequence);
}

void GameLayer::onEnter()
{
    Layer::onEnter();
    
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameLayer::onContactBegin, this);
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    
    dispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
}

void GameLayer::onExit()
{
    Layer::onExit();
    //this->airplane_body->setDynamic(false); //防止其继续运动
}

void GameLayer::onTouch()
{
    if(this->gameStatus == GAME_STATUS_OVER) {
        return;
    }
    //加音效
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("bounce.mp3");
    if(this->gameStatus == GAME_STATUS_READY) {
        this->airplane->bounce();
        this->gameStatus = GAME_STATUS_START;
        //this->createMonster();
    }else if(this->gameStatus == GAME_STATUS_START) {
        this->airplane->getPhysicsBody()->setVelocity(Vect(0, 260));
    }
}


bool GameLayer::onContactBegin(const PhysicsContact& contact) {
    this->gameOver();
    return true;
}

bool GameLayer::checkHit()
{
    if(airplane->getPositionY() < 50)  return true;
    return false;
}

void GameLayer::gameStart()
{
    gameStatus = GAME_STATUS_READY;
    this->scheduleUpdate();//启动默认更新
}

//此处留有接口,处理游戏结束后的后勤工作
void GameLayer::gameOver()
{
    if(this->gameStatus == GAME_STATUS_OVER) {
        return;
    }
    this->gameStatus = GAME_STATUS_OVER;
    this->airplane->die();
    removeChild(pauseNode);
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("error.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("crash.wav");
    scheduleOnce(schedule_selector(GameLayer::gameOverInformer), 2.0f);
    }

void GameLayer::gameOverInformer(float dt)
{
    delegator->onGameEnd(this->score, this->bestScore);
}


void GameLayer::updateScore()
{
    this->score += 1;
    
    ostringstream  ostr;
    ostr << this->score;
    string str(ostr.str());
    
    this->scoreLabel->setString(str);
    this->scoreLabel->setVisible(true);
}

//void GameLayer::updateSpeed()
//{
//    GameBackgroundLayer::scrollSpeedUp();
//    //
//}

void GameLayer::update(float delta)
{
    if(gameStatus == GAME_STATUS_START)
    {
        this->updateScore();
    }
    
    //地面碰撞检测
    if(gameStatus == GAME_STATUS_START&&checkHit())
    {
        this->gameOver();
        insertGameOver();
    }
    
    else if(gameStatus == GAME_STATUS_OVER)
    {
        this->gameOver();
        this->insertGameOver();
    }
}

void GameLayer::insertGameOver()
{
    this->label2 = Label::createWithTTF("Game Over!","fonts/Marker Felt.ttf", 40);
    label2->setPosition(Vec2((origin.x + visibleSize.width)/2,origin.y + visibleSize.height/2 + 80));
    this->addChild(label2);
    unscheduleUpdate();
}

void GameLayer::menuPauseCallback(Ref* pSender)
{
    //为使得飞行器在暂停时间不受重力影响，取消物理世界的重力，并设速度为0
    
    airplane->getPhysicsBody()->setVelocity(Vec2(0,0));
    Vect ungravity(0, 0);
    m_world->setGravity(ungravity);
    
    this->fadeInMenuResume();
    this->removeChild(pauseNode);
    this->gameStatus = GAME_STATUS_PAUSE;
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("stop.wav");
    Director::getInstance()->pause();

}

void GameLayer::menuResumeCallback(Ref* psender)
{
    //物理世界恢复正常
    Vect gravity(0, -900);
    m_world->setGravity(gravity);
    
    this->gameStatus = GAME_STATUS_START;
    Director::getInstance()->resume();
    removeChild(resumeNode);
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("stop.wav");
    this->initPauseMenu();
}

void GameLayer::fadeInMenuResume()
{
    this->resumeNode = Node::create();
    Sprite* resumeBtn = Sprite::create("Btn_resume.png");
    Sprite* resumeBtnActive = Sprite::create("Btn_resume.png");
    resumeBtnActive->setPositionY(5);
    auto menuItem = MenuItemSprite::create(resumeBtn,resumeBtnActive,NULL,CC_CALLBACK_1(GameLayer::menuResumeCallback,this));
    auto menu = Menu::create(menuItem,NULL);
    menu->setPosition(Point(origin.x + visibleSize.width/2 + 100,origin.y + visibleSize.height/2 + 100));
    resumeNode->setScale(0.8);
    resumeNode->addChild(menu);
    addChild(resumeNode);
    
    //fade in the two buttons
    auto fadeIn = FadeIn::create(3.0f);
    //tmpNode->stopAllActions();
    resumeNode->runAction(fadeIn);
    auto sequence = Sequence::create(fadeIn,NULL);
    resumeNode->stopAllActions();
    resumeNode->runAction(sequence);
}