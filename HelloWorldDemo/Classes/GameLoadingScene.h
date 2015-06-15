//
//  GameLoadingScene.h
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/15.
//
//

#ifndef __HelloWorldDemo__GameLoadingScene__
#define __HelloWorldDemo__GameLoadingScene__

#include <stdio.h>
#include "WelcomeScene.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"

using namespace cocos2d;
using namespace CocosDenshion;

class LoadingScene : public Scene {
public:

    LoadingScene();
    
    ~LoadingScene();

    virtual bool init();
    
    CREATE_FUNC(LoadingScene);
    
    void onEnter() override;
    
private:

    void loadingCallBack();
};

#endif /* defined(__HelloWorldDemo__GameLoadingScene__) */
