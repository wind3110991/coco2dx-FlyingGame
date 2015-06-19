//
//  AboutLayer.h
//  HelloWorldDemo
//
//  Created by 骏宇 on 15/6/19.
//
//

#ifndef __HelloWorldDemo__AboutLayer__
#define __HelloWorldDemo__AboutLayer__

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;

class AboutLayer : public Layer{
public:
    AboutLayer(void);
    ~AboutLayer(void);
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    // implement the "static create()" method manually
    CREATE_FUNC(AboutLayer);
private:
    /**
     * The start button has been pressed will call this function
     */
    
private:
    Sprite *aboutImg;
};
#endif /* defined(__HelloWorldDemo__AboutLayer__) */
