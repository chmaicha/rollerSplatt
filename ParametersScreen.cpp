#include "/Users/mac_hd/Desktop/namegame/Classes/ParametersScreen.h"
#include"/Users/mac_hd/Desktop/namegame/Classes/nivaeu1.h"
#include"/Users/mac_hd/Desktop/namegame/Classes/MainMenu.h"
#include "/Users/mac_hd/Desktop/namegame/Classes/niveau2.h"
#include "/Users/mac_hd/Desktop/namegame/cocos2d/cocos/editor-support/cocostudio/SimpleAudioEngine.h"
USING_NS_CC;

Scene* ParametersMenu::createScene()
{
 //scene is an autorelease object
    auto scene = Scene::create();
    //scene is an autorelease object
    auto Layer = ParametersMenu::create();
    //add layer as a child to scene
    scene->addChild(Layer);
    //return the scene
    return scene;
}
// on "init": initialisation of the instances
bool ParametersMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
  Point origin = Director::getInstance()->getVisibleOrigin();

    auto resumeItem =
      
    MenuItemImage::create("/Users/mac_hd/Desktop/namegame/Resources/images/home.png",
      "",
      CC_CALLBACK_1(ParametersMenu::GoHome, this));
//appel de la fonction home lors du clic sur le putton "maison"
      auto music =
      
    MenuItemImage::create("/Users/mac_hd/Desktop/namegame/Resources/images/music.png",
      "",
      CC_CALLBACK_1(ParametersMenu::Music, this));
    //appel de la fonction home lors du clic sur le putton "nusic"
      auto mainMenuItem =
     
    MenuItemImage::create("/Users/mac_hd/Desktop/namegame/Resources/images/mute.png",
      "/Users/mac_hd/Desktop/namegame/Resources/images/unmute.png",
      CC_CALLBACK_1(ParametersMenu::Mute, this));
    //appel de la fonction back lors du clic sur le putton "fleche"
    auto back =
    MenuItemImage::create("/Users/mac_hd/Desktop/namegame/Resources/images/back.png",
      "/Users/mac_hd/Desktop/namegame/Resources/images/unmute.png",
      CC_CALLBACK_1(ParametersMenu::GoBack, this));
    
    auto menu = Menu::create(resumeItem, music, mainMenuItem,back,
      NULL);
      menu->alignItemsVerticallyWithPadding(visibleSize.height / 2000);
      this->addChild(menu);
   
    
    auto bgparameters = Sprite::create("/Users/mac_hd/Desktop/namegame/Resources/images/Parameters-2-2.png");
        
    bgparameters->setPosition(Point((visibleSize.width/2 ) +origin.x, (visibleSize.height/2) + origin.y));
     // sets the position of the background sprite at the center ofthe screen using the visible size, which is the area of the screen that is available ona particular device, as there are different screen sizes
        this->addChild(bgparameters, -1);
    
    
    return true;
}

void ParametersMenu::GoHome(cocos2d::Ref *pSender)
{
    auto scene = HelloWorld::createScene();
  
    Director::getInstance()->replaceScene(scene);
}
void ParametersMenu::Music(cocos2d::Ref *pSender)
{

    CocosDenshion::SimpleAudioEngine::getInstance()->
           setBackgroundMusicVolume(0.5);

}
   void ParametersMenu::Mute(cocos2d::Ref *pSender)
   {
     
       CocosDenshion::SimpleAudioEngine::getInstance()->
              setBackgroundMusicVolume(0);
   }


void ParametersMenu::GoBack(cocos2d::Ref *pSender)
//
{
    auto scene = GameScreen::createScene();
    Director::getInstance()->replaceScene( (TransitionFade::create(1, scene, Color3B(255,255,255))));
}
