//
//  MyHelloScene.cpp
//  tetris
//
//  Created by 王冬晓 on 14/12/5.
//
//

#include "MyHelloScene.h"
#include "DrawMap.h"

USING_NS_CC;
MyHelloScene * MyHelloScene::create1()
{
    auto scene = new MyHelloScene;
    if (scene && scene->init()) {
        scene->autorelease();
        return scene;
    }
    else
    {
        delete scene;
        scene = NULL;
        return nullptr;
    }
}

Scene* MyHelloScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MyHelloScene::create1();
    scene->addChild(layer);
    return scene;
}

bool MyHelloScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // Create label for display purposes
    label = cocos2d::Label::createWithTTF("Tetris!", "Marker Felt.ttf", 50);
    label->setPosition(Point(visibleSize.width / 2 + origin.x,origin.y + visibleSize.height -100));
    label->setHorizontalAlignment(TextHAlignment::CENTER);
    this->addChild(label);
    
    auto labelStartGame = cocos2d::Label::createWithTTF("Start Game", "Marker Felt.ttf", 40);
    auto labelOption = cocos2d::Label::createWithTTF("Option", "Marker Felt.ttf", 40);
    auto labelExit = cocos2d::Label::createWithTTF("Exit", "Marker Felt.ttf", 40);
    
    
    auto keyboardButtonItem1 = MenuItemLabel::create(labelStartGame, CC_CALLBACK_1(MyHelloScene:: keyboardButtonCallback,this,2));
    auto keyboardButtonItem2 = MenuItemLabel::create(labelOption, CC_CALLBACK_1(MyHelloScene:: keyboardButtonCallback,this,2));
    auto keyboardButtonItem3 = MenuItemLabel::create(labelExit, CC_CALLBACK_1(MyHelloScene:: menuCloseCallback,this));
    keyboardButtonItem1->setPosition(Point(visibleSize.width/2, 330));
    keyboardButtonItem2->setPosition(Point(visibleSize.width/2, 220));
    keyboardButtonItem3->setPosition(Point(visibleSize.width/2, 100));
    
    auto keyboardButtonMenu = Menu::create(keyboardButtonItem1,keyboardButtonItem2,keyboardButtonItem3, NULL);
    keyboardButtonMenu->setPosition(Point::ZERO);
    
    this->addChild(keyboardButtonMenu, 1);
    
    auto sprite = Sprite::create("Tetris.png");
    sprite->setPosition(Point(200,visibleSize.height - 80));
    this->addChild(sprite);
    return true;
}

void MyHelloScene::keyboardButtonCallback(Ref * sender,int count)
{
    auto *scene1 = DrawMap::createScene();
    Director::getInstance()->replaceScene(scene1);
}

void MyHelloScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
