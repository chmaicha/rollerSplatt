

#include "/Users/mac_hd/Desktop/namegame/Classes/MainMenu.h"
#include "/Users/mac_hd/Desktop/namegame/Classes/niveau2.h"
#include "/Users/mac_hd/Desktop/namegame/Classes/START3.h"
#include "/Users/mac_hd/Desktop/namegame/Classes/niveau3.h"

USING_NS_CC;

Scene* level3::createScene() 
{
 //scene is an autorelease object
    auto scene = Scene::create();
    //scene is an autorelease object
    auto Layer = level3::create();
    //add layer as a child to scene
    scene->addChild(Layer);
    //return the scene
    return scene;
}
// on "init": initialisation of the instances
bool level3::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

Size visibleSize = Director::getInstance()->getVisibleSize();
Point origin = Director::getInstance()->getVisibleOrigin();
    

auto playItem =MenuItemImage::create("/Users/mac_hd/Desktop/namegame/Resources/images/MENU.PLAY.png",
                                     "/Users/mac_hd/Desktop/namegame/Resources/images/MENU.PLAY.png",
                                       CC_CALLBACK_1(level3::GoTolevel3,this));//The number 1 at the end of CC_CALLBACK_1 specifies how many parameters the function that is being called takes

auto menu = Menu::create( playItem, NULL); //creates a menu with the Menu items.
    menu->alignItemsHorizontally();
menu->setPosition(Point(250,210));
    
this->addChild(menu,3); // adds the menu as a child to the scene
auto backgroundSprite = Sprite::create("/Users/mac_hd/Desktop/namegame/Resources/images/leveel1.png");
    
backgroundSprite->setPosition(Point((visibleSize.width/2 ) +origin.x, (visibleSize.height/2) + origin.y));
 // sets the position of the background sprite at the center ofthe screen using the visible size, which is the area of the screen that is available ona particular device, as there are different screen sizes
    this->addChild(backgroundSprite, -1);
    return true;
}
//the function "GoToGameScen" creates a local scene instance of GameScene
void level3::GoTolevel3(cocos2d::Ref *pSender)
{

    auto scene = niveau3::createScene();
    Director::getInstance()->replaceScene( (TransitionFade::create(1, scene, Color3B(255,255,255))));
}
