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
    //设置初始滚动速度
    this->speedX = 3;
    this->initBackground();
    return true;
}

void GameBackgroundLayer::onEnter()
{
    Node::onEnter();
}

void GameBackgroundLayer::onExit()
{
    Node::onExit();
}

//初始化滚动背景
void GameBackgroundLayer::initBackground()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
   //  把两张背景地图加载进来
    this->background_1 = Sprite::create("gamebackgrounds1.png");
    this->background_1->setAnchorPoint(Vec2(0, 0));
    this->background_1->setPosition(0, 0);
    this->addChild(this->background_1);
    
    this->background_2 = Sprite::create("gamebackgrounds1.png");
    this->background_2->setAnchorPoint(Vec2(0, 0));
    this->background_2->setPosition(this->background_1->getPositionX() + this->background_1->getContentSize().width , 0);
    this->addChild(this->background_2);
 
    //schedule(schedule_selector(GameBackgroundLayer::scrollSpeedUp), 1.0f, kRepeatForever, 2.0f);
//测试-------------------------------------------------------------------------------------------------------------

    
    this->testMonster1 = Sprite::create("aircraft.png");
    this->testMonster1->setScale(0.8);
    this->testMonster1->setPosition(visibleSize.width/2, visibleSize.height/2 - rand()%11*31);
    PhysicsBody *body_1 = PhysicsBody::create();
    body_1->addShape(PhysicsShapeCircle::create(BIRMONSTER_RADIUS));
    body_1->setDynamic(true);
    body_1->setLinearDamping(0.0f);
    body_1->setGravityEnable(false);
    body_1->setCategoryBitmask(0x0000000C);
    body_1->setContactTestBitmask(0x00000002);
    testMonster1->setPhysicsBody(body_1);
    this->addChild(this->testMonster1);
    
    this->testMonster2 = Sprite::create("aircraft.png");
    this->testMonster2->setScale(0.8);
    this->testMonster2->setPosition(visibleSize.width + this->background_1->getContentSize().width,  + rand()%11*22);
    PhysicsBody *body_2 = PhysicsBody::create();
    body_2->addShape(PhysicsShapeCircle::create(BIRMONSTER_RADIUS));
    body_2->setDynamic(true);
    body_2->setLinearDamping(0.0f);
    body_2->setGravityEnable(false);
    body_2->setCategoryBitmask(0x0000000C);
    body_2->setContactTestBitmask(0x00000002);
    testMonster2->setPhysicsBody(body_2);
    this->addChild(this->testMonster2);
    
    ActionInterval *forwardBy1 = CCMoveBy::create(2, Point(visibleSize.width/2, visibleSize.height/2 - rand()%11*10));
    ActionInterval *backBy1 = forwardBy1->reverse();
    Action *action1 = CCRepeat::create((CCSequence::create(forwardBy1, backBy1, NULL)), 4);
    testMonster1->runAction(action1);
    
    ActionInterval *forwardBy2 = CCMoveBy::create(2, Point(visibleSize.width/2 , visibleSize.height/2 + rand()%11*10));
    ActionInterval *backBy2 = forwardBy2->reverse();
    Action *action2 = CCRepeat::create((CCSequence::create(forwardBy2, backBy2, NULL)), 4);
    
    testMonster2->runAction(action2);
    
    //testMonster3
    
    birdmonster1 = BirdMonsterObj::getInstance();
    birdmonster1->createMonster();
    birdmonster1->setPosition(visibleSize.width/2  - rand()%11*20,  rand()%11*20);
    PhysicsBody *body_3 = PhysicsBody::create();
    body_3->addShape(PhysicsShapeCircle::create(BIRMONSTER_RADIUS-10));
    body_3->setDynamic(true);
    body_3->setLinearDamping(0.0f);
    body_3->setGravityEnable(false);
    body_3->setCategoryBitmask(0x0000000C);
    body_3->setContactTestBitmask(2);
    birdmonster1->setPhysicsBody(body_3);
    addChild(birdmonster1);
    
    
    birdmonster2 = BirdMonsterObj::getInstance();
    birdmonster2->createMonster();
    birdmonster2->setPosition(visibleSize.width/4 + this->background_1->getContentSize().width, visibleSize.height - rand()%11*20);
    PhysicsBody *body_4 = PhysicsBody::create();
    body_4->addShape(PhysicsShapeCircle::create(BIRMONSTER_RADIUS-10));
    body_4->setDynamic(true);
    body_4->setLinearDamping(0.0f);
    body_4->setGravityEnable(false);
    body_4->setCategoryBitmask(0x0000000C);
    body_4->setContactTestBitmask(2);
    birdmonster2->setPhysicsBody(body_4);
    addChild(birdmonster2);
    
    birdmonster3 = BirdMonsterObj::getInstance();
    birdmonster3->createMonster();
    birdmonster3->setPosition(visibleSize.width + this->background_1->getContentSize().width - rand()%11*10, visibleSize.height - rand()%11*40);
    PhysicsBody *body_5 = PhysicsBody::create();
    body_5->addShape(PhysicsShapeCircle::create(BIRMONSTER_RADIUS-10));
    body_5->setDynamic(true);
    body_5->setLinearDamping(0.0f);
    body_5->setGravityEnable(false);
    body_5->setCategoryBitmask(0x0000000C);
    body_5->setContactTestBitmask(2);
    birdmonster3->setPhysicsBody(body_5);
    addChild(birdmonster3);
    
//测试-------------------------------------------------------------------------------------------------------------
    
    

    
     //防止背景滚动的时候两张图片衔接部分出现黑边
    this->background_1->getTexture()->setAliasTexParameters();

}



//设置滚动背景
void GameBackgroundLayer::scrollBackground()
{
    
    // 计算出地图下次滚动到的X轴坐标，这里是向右位移
    auto nextPos_1 = this->background_1->getPositionX() - this->speedX;
    auto nextPos_2 = this->background_2->getPositionX() - this->speedX;
    
//测试-------------------------------------------------------------------------------------------------------------
    auto nextPos_m1 = this->testMonster1->getPositionX() - this->speedX;
    auto nextPos_m2 = this->testMonster2->getPositionX() - this->speedX;
    auto nextPos_m3 = this->birdmonster1->getPositionX() - this->speedX;
    auto nextPos_m4 = this->birdmonster2->getPositionX() - this->speedX;
    auto nextPos_m5 = this->birdmonster3->getPositionX() - this->speedX;
//测试-------------------------------------------------------------------------------------------------------------
    
    
    this->background_1->setPositionX(nextPos_1);
    this->background_2->setPositionX(nextPos_2);

//测试-------------------------------------------------------------------------------------------------------------
    this->testMonster1->setPositionX(nextPos_m1);
    this->testMonster2->setPositionX(nextPos_m2);
    this->birdmonster1->setPositionX(nextPos_m3);
    this->birdmonster2->setPositionX(nextPos_m4);
    this->birdmonster3->setPositionX(nextPos_m5);
//测试-------------------------------------------------------------------------------------------------------------
    
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
        
        auto *s = this->testMonster1;
        this->testMonster1 = this->testMonster2;
        this->testMonster2 = s;
        
        this->birdmonster1->setPositionX(this->background_2->getPositionX() + this->background_2->getContentSize().width - rand()%11*10);
        this->birdmonster1->setPositionY(visibleSize.height/2 + rand()%11*10);
        
        auto *temp = this->birdmonster1;
        this->birdmonster1 = this->birdmonster2;
        this->birdmonster2 = temp;
        
        
//测试-------------------------------------------------------------------------------------------------------------
    }
}

Animation* GameBackgroundLayer::createAnimation()
{
    auto animation = Animation::create();
    
    for( int i=1;i<26;i++)
    {
        char szName[100] = {0};
        sprintf(szName, "birdmonster%d.png", i);
        animation->addSpriteFrameWithFile(szName);
    }
    
    animation->setDelayPerUnit(2.8f / 59.0f);
    animation->setRestoreOriginalFrame(true);
    return animation;
}


void GameBackgroundLayer::scrollSpeedUp()
{
    this->speedX += 1;
    log("asdasdas");
}