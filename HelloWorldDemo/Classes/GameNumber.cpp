//
//  GameNumber.cpp
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/13.
//
//

#include "GameNumber.h"


GameNumber::GameNumber(void)
{}

GameNumber::~GameNumber(void)
{}

GameNumber* GameNumber::shareNumberObj = nullptr;
GameNumber* GameNumber::getInstance(){
if(shareNumberObj == NULL){
    shareNumberObj = new GameNumber();
    if(!shareNumberObj->init()){
        delete(shareNumberObj);
        shareNumberObj = NULL;
        CCLOG("ERROR: Could not init shareNumberObj");
    }
}
return shareNumberObj;
}