#include "/Users/mac_hd/Desktop/namegame/Classes/MainMenu.h"
#include"/Users/mac_hd/Desktop/namegame/Classes/start1.h"
#include "/Users/mac_hd/Desktop/namegame/cocos2d/cocos/editor-support/cocostudio/SimpleAudioEngine.h"
#include "/Users/mac_hd/Desktop/namegame/Classes/niveau3.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
 //scene is an autorelease object
    auto scene = Scene::create();
    //scene is an autorelease object
    auto Layer = HelloWorld::create();
    //add layer as a child to scene
    scene->addChild(Layer);
    //return the scene
    return scene;
}
// on "init": initialisation of the instances
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

Size visibleSize = Director::getInstance()->getVisibleSize();
Point origin = Director::getInstance()->getVisibleOrigin();
    
auto menuTitle =MenuItemImage::create("","");//The image that has to be displayed when the title is tapped on (as the title cannot be tapped on, it is the same as the default image to give the illusion of a static item)
auto playItem =MenuItemImage::create("/Users/mac_hd/Desktop/namegame/Resources/images/MENU.PLAY.png",
                                     "/Users/mac_hd/Desktop/namegame/Resources/images/MENU.PLAY.png",
                                       CC_CALLBACK_1(HelloWorld::GoTostart1, this));//The number 1 at the end of CC_CALLBACK_1 specifies how many parameters the function that is being called takes

auto menu = Menu::create(menuTitle, playItem, NULL); //creates a menu with the Menu items.
menu->alignItemsVerticallyWithPadding(visibleSize.height / 2);
    //menu->setContentSize(Size::ZERO);
    
this->addChild(menu); // adds the menu as a child to the scene
auto backgroundSprite = Sprite::create("/Users/mac_hd/Desktop/namegame/Resources/images/MENU.BAKGROUND.png");
    
backgroundSprite->setPosition(Point((visibleSize.width/2 ) +origin.x, (visibleSize.height/2) + origin.y));
 // sets the position of the background sprite at the center ofthe screen using the visible size, which is the area of the screen that is available ona particular device, as there are different screen sizes
    this->addChild(backgroundSprite, -1);

   
       CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("/Users/mac_hd/Desktop/namegame/audio/WhatsApp Audio 2022-01-05 at 14.56.31.mpeg");
    CocosDenshion::SimpleAudioEngine::getInstance()->
           setBackgroundMusicVolume(0.5);
      
    return true;
}
//the function "GoToGameScen" creates a local scene instance of GameScene
void HelloWorld::GoTostart1(cocos2d::Ref *pSender)
{

    auto scene = level1::createScene();
    Director::getInstance()->replaceScene( (TransitionFade::create(1, scene, Color3B(255,255,255))));
}
