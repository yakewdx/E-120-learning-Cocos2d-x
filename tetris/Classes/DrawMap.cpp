//
//  DrawMap.cpp
//  tetris
//
//  Created by 王冬晓 on 14/12/10.
//
//

#include "DrawMap.h"
#include "TetrisField.h"

USING_NS_CC;


/****************************************************************
 ColoredboxMap
 ****************************************************************/

std::map<int,std::string> _map;
std::string key_0 = "Nobox.png";
std::string key_1 = "Bluebox.png";
std::string key_2 = "Redbox.png";
std::string key_3 = "Graybox.png";
std::string key_4 = "Orangebox.png";
std::string key_5 = "Purplebox.png";
std::string key_6 = "Skybluebox.png";
std::string key_7 = "Yellowbox.png";

//***************************************************************

TetrisField field;
unsigned int width = field.GetWidth();
unsigned int height = field.GetHeight();
auto colors = new unsigned int[width * height];

cocos2d::Vector<Sprite *> a;


Scene * DrawMap::createScene()
{
    auto scene = Scene::create();
    auto layer = DrawMap::create();
    scene->addChild(layer);
    return scene;
}
void DrawMap::init_map(cocos2d::Vector<Sprite *>&a)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    for (int i = 27; i >= 0; i--)
    {
        for (int j = 0; j < 10; j++)
        {
            Sprite * b = Sprite::create("Nobox.png");
            b->setPosition(Point(140+j*57,visibleSize.height-200-i*56.6));
            a.pushBack(b);
            this->addChild(b);
        }
    }
}
void DrawMap::freshMap(std::map<int,std::string>_map, cocos2d::Vector<Sprite *>&a)
{
    
    field.Update();
    field.CopyColors(colors);
    for (int y = height - 1; y >= 0; y--)
    {
        for (int x = 0; x < static_cast<int>(width); x++)
        {
                a.at(x + y * width)->setTexture(_map.at(colors[x + y * width]));
        }
    }

}

void DrawMap::menuCallback(Ref *sender, const cocos2d::Vector<Sprite *>t, const int TYPE)
{
    switch (TYPE) {
        case 0:
            field.Rotate(3);
            break;
        case 1:
            field.MoveY(-1);
            break;
        case 2:
            field.MoveX(1);
            break;
        case 3:
            field.MoveX(-1);
            break;
        default:
            break;
    }
    
    field.CopyColors(colors);
    for (int y = height - 1; y >= 0; y--)
    {
        for (int x = 0; x < static_cast<int>(width); x++)
        {
            a.at(x + y * width)->setTexture(_map.at(colors[x + y * width]));
        }
    }
}
void DrawMap::update(float delta){
    
    freshMap(_map, a);
    
}

bool DrawMap::init()
{
    if (!Layer::init()) {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    
    _map.insert(std::pair<int,std::string>(0, key_0));
    _map.insert(std::pair<int,std::string>(1, key_1));
    _map.insert(std::pair<int,std::string>(2, key_2));
    _map.insert(std::pair<int,std::string>(3, key_3));
    _map.insert(std::pair<int,std::string>(4, key_4));
    _map.insert(std::pair<int,std::string>(5, key_5));
    _map.insert(std::pair<int,std::string>(6, key_6));
    _map.insert(std::pair<int,std::string>(7, key_7));
    
    /****************************************************************
     ColoredboxMap
     ****************************************************************/
    
    Sprite *background = Sprite::create("background.png");
    background->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
    this->addChild(background,-2);
    init_map(a);
    
    auto upbutton = MenuItemImage::create("up_Button.png","up_Button.png", CC_CALLBACK_1(DrawMap::menuCallback,this,a,0));
    auto downbutton = MenuItemImage::create("down_Button.png","down_Button.png", CC_CALLBACK_1(DrawMap::menuCallback,this,a,1));
    auto rightbutton = MenuItemImage::create("right_Button.png","right_Button.png", CC_CALLBACK_1(DrawMap::menuCallback,this,a,2));
    auto leftbutton = MenuItemImage::create("left_Button.png","left_Button.png", CC_CALLBACK_1(DrawMap::menuCallback,this,a,3));
    auto buttonMenu = Menu::create(upbutton,downbutton,rightbutton,leftbutton, NULL);
    
    upbutton->setPosition(100, 300);
    downbutton->setPosition(100,100);
    leftbutton->setPosition(0,200);
    rightbutton->setPosition(200,200);
    
    buttonMenu->setPosition(Point(800,700));
    this->addChild(buttonMenu);
    this->schedule(schedule_selector(DrawMap::update), 1.0f);
    // Input:
    
    
    Label *score = Label::createWithTTF("Score", "Marker Felt.ttf", 62);
    score->setPosition(Point(visibleSize.width - 180, visibleSize.height - 150));
    this->addChild(score);
    
    Label *next = Label::createWithTTF("Next", "Marker Felt.ttf", 62);
    next->setPosition(Point(visibleSize.width - 180, visibleSize.height - 400));
    this->addChild(next);
    return true;
}