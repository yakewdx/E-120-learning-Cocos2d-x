//
//  MyHelloScene.h
//  tetris
//
//  Created by 王冬晓 on 14/12/5.
//
//

#ifndef __tetris__MyHelloScene__
#define __tetris__MyHelloScene__

#include <cocos2d.h>
#include <SimpleAudioEngine.h>

class MyHelloScene : public cocos2d::Layer
{
public:
    //initialize:
    virtual bool init();
    static cocos2d:: Scene* createScene();
    void menuCloseCallback(Ref* pback);
    static MyHelloScene * create1();
    cocos2d::Label *label;
    void keyboardButtonCallback(Ref * sender, int count);

};


#endif /* defined(__tetris__MyHelloScene__) */
