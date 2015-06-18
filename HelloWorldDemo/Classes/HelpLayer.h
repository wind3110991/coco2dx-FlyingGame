//
//  HelpLayer.h
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/18.
//
//

#ifndef __HelloWorldDemo__HelpLayer__
#define __HelloWorldDemo__HelpLayer__

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;

class HelpLayer : public Layer{
public:
    HelpLayer(void);
    ~HelpLayer(void);
    virtual bool init();
//    virtual void onEnter();
//    virtual void onExit();
    // implement the "static create()" method manually
    CREATE_FUNC(HelpLayer);
    
private:
    /**
     * The start button has been pressed will call this function
     */
    
private:
    Sprite *helpImg;
};

#endif /* defined(__HelloWorldDemo__HelpLayer__) */
