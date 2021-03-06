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
    
   //  把两张背景地图加载进来
    this->background_1 = Sprite::create("gamebackgrounds1.png");
    this->background_1->setAnchorPoint(Vec2(0, 0));
    this->background_1->setPosition(0, 0);
    this->addChild(this->background_1);
    
    this->background_2 = Sprite::create("gamebackgrounds1.png");
    this->background_2->setAnchorPoint(Vec2(0, 0));
    this->background_2->setPosition(this->background_1->getPositionX() + this->background_1->getContentSize().width , 0);
    this->addChild(this->background_2);
 
//测试-------------------------------------------------------------------------------------------------------------

    birdMonsterFactory();
    aircraftMonsterFactory();
    rocketMonsterFactory();
    
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
    auto nextPos_m6 = this->birdmonster4->getPositionX() - this->speedX;
    auto nextPos_m7 = this->rocketmonster1->getPositionX() - this->speedX;
    auto nextPos_m8 = this->rocketmonster2->getPositionX() - this->speedX;
//测试-------------------------------------------------------------------------------------------------------------
    
    
    this->background_1->setPositionX(nextPos_1);
    this->background_2->setPositionX(nextPos_2);

//测试-------------------------------------------------------------------------------------------------------------
    this->testMonster1->setPositionX(nextPos_m1);
    this->testMonster2->setPositionX(nextPos_m2);
    this->birdmonster1->setPositionX(nextPos_m3);
    this->birdmonster2->setPositionX(nextPos_m4);
    this->birdmonster3->setPositionX(nextPos_m5);
    this->birdmonster4->setPositionX(nextPos_m6);
    this->rocketmonster1->setPositionX(nextPos_m7);
    this->rocketmonster2->setPositionX(nextPos_m8);

//测试-------------------------------------------------------------------------------------------------------------
    
    // 当一张地图移除屏幕边界的时候，重新放置到另一张地图的右边
    if(fabs(nextPos_1) == this->background_1->getContentSize().width) //当nextPos_1为末端
    {
        this->background_1->setPositionX(this->background_2->getPositionX() + this->background_2->getContentSize().width);
        
        Sprite *t = this->background_1;
        this->background_1 = this->background_2;
        this->background_2 = t;
        
//测试-------------------------------------------------------------------------------------------------------------
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
        
        this->birdmonster3->setPositionX(this->background_2->getPositionX() + this->background_2->getContentSize().width - rand()%11*10);
        this->birdmonster3->setPositionY(visibleSize.height/2 + rand()%11*10);
        
        auto *temp1 = this->birdmonster3;
        this->birdmonster3 = this->birdmonster4;
        this->birdmonster4 = temp1;
        
        
        this->rocketmonster1->setPositionX(this->background_2->getPositionX()/3 + this->background_2->getContentSize().width);
        this->rocketmonster1->setPositionY(0);
        
        auto *temp2 = this->rocketmonster1;
        this->rocketmonster1 = this->rocketmonster2;
        this->rocketmonster2 = temp2;
        
        ccBezierConfig bezierCon;
        bezierCon.controlPoint_1 = CCPointMake(visibleSize.width/3, 0);//控制点1
        bezierCon.controlPoint_2 = CCPointMake(visibleSize.width/2, 10);//控制点2
        bezierCon.endPosition = CCPointMake(visibleSize.width/10, visibleSize.height + 100);// 结束位置
        //CCActionInterval * action = CCBezierTo::create(2, bezierCon);
        CCActionInterval * action5= CCBezierBy::create(3, bezierCon);//支持反向
        //CCActionInterval * action1 = action->reverse();
        rocketmonster1->runAction(action5);
        

//测试-------------------------------------------------------------------------------------------------------------
    }
}

void GameBackgroundLayer::birdMonsterFactory()
{
    
    //testMonster3
    birdmonster1 = new BirdMonsterObj();
    birdmonster1->createMonster();
    birdmonster1->setPosition(visibleSize.width/2  - rand()%11*10,  rand()%11*50);
    PhysicsBody *body_3 = PhysicsBody::create();
    body_3->addShape(PhysicsShapeCircle::create(BIRDMONSTER_RADIUS-10));
    body_3->setDynamic(true);
    body_3->setLinearDamping(0.0f);
    body_3->setGravityEnable(false);
    body_3->setCategoryBitmask(0x0000000C);
    body_3->setMass(200);
    body_3->setContactTestBitmask(2);
    birdmonster1->setPhysicsBody(body_3);
    addChild(birdmonster1);
    
    birdmonster2 = new BirdMonsterObj();
    birdmonster2->createMonster();
    birdmonster2->setPosition(visibleSize.width/2 + this->background_1->getContentSize().width, visibleSize.height - rand()%11*20);
    PhysicsBody *body_4 = PhysicsBody::create();
    body_4->addShape(PhysicsShapeCircle::create(BIRDMONSTER_RADIUS-10));
    body_4->setDynamic(true);
    body_4->setLinearDamping(0.0f);
    body_4->setGravityEnable(false);
    body_4->setCategoryBitmask(0x0000000C);
    body_4->setContactTestBitmask(2);
    body_4->setMass(200);
    birdmonster2->setPhysicsBody(body_4);
    addChild(birdmonster2);
    
    birdmonster3 = new BirdMonsterObj();
    birdmonster3->createMonster();
    birdmonster3->setPosition(visibleSize.width + rand()%11*5 , visibleSize.height - rand()%11*20);
    PhysicsBody *body_5 = PhysicsBody::create();
    body_5->addShape(PhysicsShapeCircle::create(BIRDMONSTER_RADIUS-10));
    body_5->setDynamic(true);
    body_5->setLinearDamping(0.0f);
    body_5->setGravityEnable(false);
    body_5->setCategoryBitmask(0x0000000C);
    body_5->setContactTestBitmask(2);
    birdmonster3->setPhysicsBody(body_5);
    addChild(birdmonster3);
    
    birdmonster4 = new BirdMonsterObj();
    birdmonster4->createMonster();
    birdmonster4->setPosition(visibleSize.width/4 + this->background_1->getContentSize().width + rand()%11*5 , rand()%11*22);
    PhysicsBody *body_6 = PhysicsBody::create();
    body_6->addShape(PhysicsShapeCircle::create(BIRDMONSTER_RADIUS-10));
    body_6->setDynamic(true);
    body_6->setLinearDamping(0.0f);
    body_6->setGravityEnable(false);
    body_6->setCategoryBitmask(0x0000000C);
    body_6->setContactTestBitmask(2);
    birdmonster3->setPhysicsBody(body_6);
    addChild(birdmonster4);
}

void GameBackgroundLayer::aircraftMonsterFactory()
{
    this->testMonster1 = new AircraftMonsterObj();
    this->testMonster1->setPosition(visibleSize.width/2, visibleSize.height/2 - rand()%11*31);
    PhysicsBody *body_1 = PhysicsBody::create();
    body_1->addShape(PhysicsShapeCircle::create(BIRDMONSTER_RADIUS));
    body_1->setDynamic(true);
    body_1->setLinearDamping(0.0f);
    body_1->setGravityEnable(false);
    body_1->setCategoryBitmask(0x0000000C);
    body_1->setContactTestBitmask(0x00000002);
    body_1->setMass(2000000);
    testMonster1->setPhysicsBody(body_1);
    this->addChild(this->testMonster1);
    
    this->testMonster2 = new AircraftMonsterObj();
    this->testMonster2->setPosition(visibleSize.width + this->background_1->getContentSize().width,  + rand()%11*22);
    PhysicsBody *body_2 = PhysicsBody::create();
    body_2->addShape(PhysicsShapeCircle::create(BIRDMONSTER_RADIUS));
    body_2->setDynamic(true);
    body_2->setLinearDamping(0.0f);
    body_2->setGravityEnable(false);
    body_2->setCategoryBitmask(0x0000000C);
    body_2->setContactTestBitmask(0x00000002);
    body_2->setMass(2000000);
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
}

void GameBackgroundLayer::rocketMonsterFactory()
{
    rocketmonster1 = RocketMonsterObj::getInstance();
    rocketmonster1->createMonster();
    //this->rocketmonster1 = Sprite::create("rocket.png");
    this->rocketmonster1->setScale(0.8);
    this->rocketmonster1->setPosition(visibleSize.width/3, 0);
    PhysicsBody *body_1 = PhysicsBody::create();
    body_1->addShape(PhysicsShapeCircle::create(BIRMONSTER_RADIUS));
    body_1->setDynamic(true);
    body_1->setLinearDamping(0.0f);
    body_1->setGravityEnable(false);
    body_1->setCategoryBitmask(0x0000000C);
    body_1->setContactTestBitmask(0x00000002);
    body_1->setMass(2000);
    rocketmonster1->setPhysicsBody(body_1);
    this->addChild(rocketmonster1);
    
    ccBezierConfig bezierCon;
        bezierCon.controlPoint_1 = CCPointMake(visibleSize.width/3, 0);//控制点1
        bezierCon.controlPoint_2 = CCPointMake(visibleSize.width/2, 10);//控制点2
        bezierCon.endPosition = CCPointMake(visibleSize.width/10, visibleSize.height + 100);// 结束位置
        //CCActionInterval * action = CCBezierTo::create(2, bezierCon);
        CCActionInterval * action1= CCBezierBy::create(3, bezierCon);//支持反向
        //CCActionInterval * action1 = action->reverse();
        rocketmonster1->runAction(action1);

    rocketmonster2 = RocketMonsterObj::getInstance();
    rocketmonster2->createMonster();
    //this->rocketmonster1 = Sprite::create("rocket.png");
    this->rocketmonster2->setScale(0.8);
    this->rocketmonster2->setPosition(visibleSize.width/5 + this->background_1->getContentSize().width, 0);
    PhysicsBody *body_2 = PhysicsBody::create();
    body_2->addShape(PhysicsShapeCircle::create(BIRMONSTER_RADIUS));
    body_2->setDynamic(true);
    body_2->setLinearDamping(0.0f);
    body_2->setGravityEnable(false);
    body_2->setCategoryBitmask(0x0000000C);
    body_2->setContactTestBitmask(0x00000002);
    body_2->setMass(2000);
    rocketmonster1->setPhysicsBody(body_2);
    this->addChild(rocketmonster2);
    
    ccBezierConfig bezierCon1;
    bezierCon1.controlPoint_1 = CCPointMake(visibleSize.width/3, 0);//控制点1
    bezierCon1.controlPoint_2 = CCPointMake(visibleSize.width/2, 10);//控制点2
    bezierCon1.endPosition = CCPointMake(visibleSize.width/10, visibleSize.height + 100);// 结束位置
    //CCActionInterval * action = CCBezierTo::create(2, bezierCon);
    CCActionInterval * action2= CCBezierBy::create(3, bezierCon);//支持反向
    //CCActionInterval * action1 = action->reverse();
    rocketmonster1->runAction(action2);
}

//Animation* GameBackgroundLayer::createAnimation()
//{
//    auto animation = Animation::create();
//    
//    for( int i=1;i<26;i++)
//    {
//        char szName[100] = {0};
//        sprintf(szName, "birdmonster%d.png", i);
//        animation->addSpriteFrameWithFile(szName);
//    }
//    
//    animation->setDelayPerUnit(2.8f / 59.0f);
//    animation->setRestoreOriginalFrame(true);
//    return animation;
//}


void GameBackgroundLayer::scrollSpeedUp()
{
    this->speedX += 1;
    log("asdasdas");
}