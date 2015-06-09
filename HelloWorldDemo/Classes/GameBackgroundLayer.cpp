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
 //   用来缓存plist文件
//    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("gameArts-hd.plist", "gameArts-hd.png");
    
   //  把两张背景地图加载进来
    this->background_1 = cocos2d::CCSprite::create("background.png");
    this->background_1->setAnchorPoint(cocos2d::Vec2(0, 0));
    this->background_1->setPosition(0, 0);
    this->addChild(this->background_1);
    
    this->background_2 = cocos2d::CCSprite::create("background.png");
    this->background_2->setAnchorPoint(cocos2d::Vec2(0, 0));
    this->background_2->setPosition(0, this->background_1->getPositionY() + this->background_1->getContentSize().height);
    this->addChild(this->background_2);
    
     //设置初始滚动速度
    this->speedX = 1;
    
     //防止背景滚动的时候两张图片衔接部分出现黑边
    this->background_1->getTexture()->setAliasTexParameters();

}

//设置滚动背景
void GameBackgroundLayer::scrollBackground()
{
    // 计算出地图下次滚动到的X轴坐标，这里是向右位移
    auto nextPos_1 = this->background_1->getPositionX() - this->speedX;
    auto nextPos_2 = this->background_2->getPositionX() - this->speedX;
    
    this->background_1->setPositionX(nextPos_1);
    this->background_2->setPositionX(nextPos_2);
    
    // 当一张地图移除屏幕边界的时候，重新放置到另一张地图的上面
    if(fabs(nextPos_1) == this->background_1->getContentSize().width) //当nextPos_1为末端
    {
        this->background_1->setPositionY(this->background_2->getPositionY() + this->background_2->getContentSize().height);
        
        cocos2d::Sprite *t = this->background_1;
        this->background_1 = this->background_2;
        this->background_2 = t;
    }
}

//void GameBackgroundLayer::scrollBackground()
//{
//    // 计算出地图下次滚动到的Y轴坐标，这里是向下位移
//    auto nextPos_1 = this->background_1->getPositionY() - this->speedX;
//    auto nextPos_2 = this->background_2->getPositionY() - this->speedX;
//    
//    this->background_1->setPositionY(nextPos_1);
//    this->background_2->setPositionY(nextPos_2);
//    
//    // 当一张地图移除屏幕边界的时候，重新放置到另一张地图的上面
//    if(fabs(nextPos_1) == this->background_1->getContentSize().height)
//    {
//        this->background_1->setPositionY(this->background_2->getPositionY() + this->background_2->getContentSize().height);
//        
//        cocos2d::Sprite *t = this->background_1;
//        this->background_1 = this->background_2;
//        this->background_2 = t;
//    }
//}