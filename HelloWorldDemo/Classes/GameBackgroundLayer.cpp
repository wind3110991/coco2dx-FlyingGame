//
//  GameBackgroundLayer.cpp
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/9.
//
//

#include "GameBackgroundLayer.h"

GameBackgroundLayer::GameBackgroundLayer(void)
{
}

GameBackgroundLayer::~GameBackgroundLayer(void)
{
}

bool GameBackgroundLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    this->initBackground();
    
    return true;
}

//初始化滚动背景
void GameBackgroundLayer::initBackground()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
   //  把两张背景地图加载进来
    this->background_1 = CCSprite::create("gamebackground1.png");
    this->background_1->setAnchorPoint(Vec2(0, 0));
    this->background_1->setPosition(0, 0);
    this->addChild(this->background_1);
    
    this->background_2 = CCSprite::create("gamebackground1.png");
    this->background_2->setAnchorPoint(Vec2(0, 0));
   // this->background_2->setPosition(0, this->background_1->getPositionY() + this->background_1->getContentSize().height);
    this->background_2->setPosition(this->background_1->getPositionX() + this->background_1->getContentSize().width , 0);
    this->addChild(this->background_2);
 
    
//测试-------------------------------------------------------------------------------------------------------------
    PhysicsBody *body_1 = PhysicsBody::create();
    body_1->addShape(PhysicsShapeCircle::create(20));
    body_1->setDynamic(true);
    body_1->setLinearDamping(0.0f);
    body_1->setGravityEnable(false);
    
    PhysicsBody *body_2 = PhysicsBody::create();
    body_2->addShape(PhysicsShapeCircle::create(20));
    body_2->setDynamic(true);
    body_2->setLinearDamping(0.0f);
    body_2->setGravityEnable(false);

    this->testMonster1 = CCSprite::create("birdmonster.png");
    this->testMonster1->setScale(0.8);
    this->testMonster1->setPosition(visibleSize.width/2, visibleSize.height/2 - rand()%11*10);
//    testMonster1->setPhysicsBody(body_1);
    this->addChild(this->testMonster1);
    
    this->testMonster2 = CCSprite::create("birdmonster.png");
    this->testMonster2->setScale(0.8);
    this->testMonster2->setPosition(visibleSize.width/2 + this->background_1->getContentSize().width, visibleSize.height/2 + rand()%11*10);
//    testMonster2->setPhysicsBody(body_2);
    this->addChild(this->testMonster2);
    
    ActionInterval *forwardBy1 = CCMoveBy::create(2, Point(visibleSize.width/2, visibleSize.height/2 - rand()%11*10));
    ActionInterval *backBy1 = forwardBy1->reverse();
    Action *action1 = CCRepeat::create((CCSequence::create(forwardBy1, backBy1, NULL)), 4);
    testMonster1->runAction(action1);
    
    ActionInterval *forwardBy2 = CCMoveBy::create(2, Point(visibleSize.width/2 + this->background_1->getContentSize().width, visibleSize.height/2 - rand()%11*10));
    ActionInterval *backBy2 = forwardBy2->reverse();
    Action *action2 = CCRepeat::create((CCSequence::create(forwardBy2, backBy2, NULL)), 4);
    testMonster2->runAction(action2);
//测试-------------------------------------------------------------------------------------------------------------
    
    
    //设置初始滚动速度
    this->speedX = 2;
    
     //防止背景滚动的时候两张图片衔接部分出现黑边
    this->background_1->getTexture()->setAliasTexParameters();

}

//设置滚动背景
void GameBackgroundLayer::scrollBackground()
{
    
    // 计算出地图下次滚动到的X轴坐标，这里是向右位移
    auto nextPos_1 = this->background_1->getPositionX() - this->speedX;
    auto nextPos_2 = this->background_2->getPositionX() - this->speedX;
    auto nextPos_m1 = this->testMonster1->getPositionX() - this->speedX;
    auto nextPos_m2 = this->testMonster2->getPositionX() - this->speedX;
    
    this->background_1->setPositionX(nextPos_1);
    this->background_2->setPositionX(nextPos_2);
    this->testMonster1->setPositionX(nextPos_m1);
    this->testMonster2->setPositionX(nextPos_m2);
    
    // 当一张地图移除屏幕边界的时候，重新放置到另一张地图的右边
    if(fabs(nextPos_1) == this->background_1->getContentSize().width) //当nextPos_1为末端
    {
        this->background_1->setPositionX(this->background_2->getPositionX() + this->background_2->getContentSize().width);
        
        Sprite *t = this->background_1;
        this->background_1 = this->background_2;
        this->background_2 = t;
        
//测试-------------------------------------------------------------------------------------------------------------
        Size visibleSize = Director::getInstance()->getVisibleSize();
        this->testMonster1->setPositionX(this->background_2->getPositionX() + this->background_2->getContentSize().width - rand()%11*10);
        this->testMonster1->setPositionY(visibleSize.height/2 + rand()%11*10);
        
        ActionInterval *forwardBy1 = CCMoveBy::create(2, Point(visibleSize.width/2, visibleSize.height/2 - rand()%11*10));
        ActionInterval *backBy1 = forwardBy1->reverse();
        Action *action1 = CCRepeat::create((CCSequence::create(forwardBy1, backBy1, NULL)), 4);
        testMonster1->runAction(action1);
        
        Sprite *s = this->testMonster1;
        this->testMonster1 = this->testMonster2;
        this->testMonster2 = s;
//测试-------------------------------------------------------------------------------------------------------------
    }
}
