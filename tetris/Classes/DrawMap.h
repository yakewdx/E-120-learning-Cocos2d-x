//
//  DrawMap.h
//  tetris
//
//  Created by 王冬晓 on 14/12/10.
//
//

#ifndef __tetris__DrawMap__
#define __tetris__DrawMap__

#include <cocos2d.h>
#include <string>

class DrawMap: public cocos2d::Layer
{    
public:
    //initialize:
    virtual bool init();
    static cocos2d:: Scene* createScene();
    CREATE_FUNC(DrawMap);
    void init_map(cocos2d::Vector<cocos2d::Sprite *>&);
    void freshMap( std::map<int,std::string>,cocos2d::Vector<cocos2d::Sprite *>&a);
    void menuCallback(Ref * sender, cocos2d::Vector<cocos2d::Sprite *>,const int TYPE);
    void update(float dt);
};

#endif /* defined(__tetris__DrawMap__) */
