//
//  niveau3.cpp
//  cocos2d
//
//  Created by Mac_HD on 4/1/2022.
//

#include "/Users/mac_hd/Desktop/namegame/Classes/niveau2.h"
 // used to include the GameScen so that the scene can be accessed
#include "/Users/mac_hd/Desktop/namegame/Classes/niveau3.h" // used to include the HelloWorldScene so that the scene can be accessed
#include "/Users/mac_hd/Desktop/namegame/Classes/ParametersScreen.h"
#include "/Users/mac_hd/Desktop/namegame/Classes/START3.h"
USING_NS_CC;

Scene* niveau3::createScene()
{
 //scene is an autorelease object
    auto scene = Scene::create();
    //scene is an autorelease object
    auto Layer = niveau3::create();
    //add layer as a child to scene
    scene->addChild(Layer);
    //return the scene
    return scene;
}
// on "init": initialisation of the instances
bool niveau3::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

Size visibleSize = Director::getInstance()->getVisibleSize();
Point origin = Director::getInstance()->getVisibleOrigin();

auto parameters =MenuItemImage::create("/Users/mac_hd/Desktop/namegame/Resources/images/settings.png",
                                        "/Users/mac_hd/Desktop/namegame/Resources/images/settings.png",                                           CC_CALLBACK_1(niveau3::GoToParamatersScene, this));
      parameters->setPosition(Point(parameters->getContentSize().width -
      (parameters->getContentSize().width / 2) + origin.x,
      visibleSize.height - parameters->getContentSize().height +
      (parameters->getContentSize().width / 2) + origin.y));
      auto menu = Menu::create(parameters, NULL);
      menu->setPosition(Point::ZERO);
      this->addChild(menu);
  
    auto backgroundSprite = Sprite::create("/Users/mac_hd/Desktop/namegame/Resources/images/unnamed.jpg");
       backgroundSprite->setPosition(Point((visibleSize.width / 2) +origin.x, (visibleSize.height / 2) + origin.y));
       this->addChild(backgroundSprite, -1);
    auto plan = Sprite::create("/Users/mac_hd/Desktop/namegame/Resources/images/Unknown-6");
   plan->setPosition(Point((visibleSize.width / 2) +origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(plan,0 );
cherrySprite = Sprite::create("/Users/mac_hd/Desktop/namegame/Resources/images/b-removebg-preview.png");
cherrySprite->setPosition(Point(193,62));
    this->addChild(cherrySprite, 2);
    this->scheduleUpdate();
    auto listener = EventListenerKeyboard::create();

    listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        keys[keyCode] = true;
    };

    listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        keys[keyCode] = false;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    this->scheduleUpdate();
     
    
    return true;
}



void niveau3::GoToParamatersScene(cocos2d::Ref *pSender)
{
    //GoToPauseScene function first creates a local scene instance of the Pause scene and then pushes it onto the stack.
    auto scene = ParametersMenu::createScene();
    Director::getInstance()->replaceScene( (TransitionFade::create(1, scene, Color3B(255,255,255))));
}


void niveau3::update(float delta) {
    Node::update(delta);
    auto leftArrow = EventKeyboard::KeyCode::KEY_LEFT_ARROW,
    rightArrow = EventKeyboard::KeyCode::KEY_RIGHT_ARROW,
    downArrow = EventKeyboard::KeyCode::KEY_DOWN_ARROW,
    upArrow = EventKeyboard::KeyCode::KEY_UP_ARROW;
    if (isKeyPressed(leftArrow)) {
        keyPressedDuration(leftArrow);
    }
    else if (isKeyPressed(rightArrow)) {
        keyPressedDuration(rightArrow);
    }
    else if (isKeyPressed(upArrow)) {
            keyPressedDuration(upArrow);
    }
    else if (isKeyPressed(downArrow)) {
            keyPressedDuration(downArrow);
    }
    
}
bool niveau3::isKeyPressed(EventKeyboard::KeyCode keyCode) {
    if (keys[keyCode]) {
        return true;
    }
    else {
        return false;
    }
    
}



void niveau3::keyPressedDuration(EventKeyboard::KeyCode code) {


    float locx = cherrySprite->getPositionX();
    float locy = cherrySprite->getPositionY();
    static int j =0 ;
    
    switch (code)
    {
       
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        
            if ((locx  > 131 )&&(locy == 90)) {
                cherrySprite->setPosition(Point(131,90));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=193; i  >132;i--){
                    drawNode->drawPoint(Point(i,75),132.0f, Color4F ::GREEN);
                    
                }
                this->addChild(drawNode);
            
              }
            else if ((locx  > 131 )&&(locx <=193)&&(locy == 62)) {
                cherrySprite->setPosition(Point(131,62));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=193; i  >132;i--){
                drawNode->drawPoint(Point(i,51),132.0f, Color4F ::GREEN);
               
                    
                }
                this->addChild(drawNode);
//                auto action = MoveTo::create(2, Point(230, 300));
//                melon->runAction(action);
           
              }
          else if ((locx  > 131 )&&(locy == 203)) {
                cherrySprite->setPosition(Point(131,203));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=305; i  >132;i--){
                    drawNode->drawPoint(Point(i,190),123.0f, Color4F ::GREEN);
                    
                }
                this->addChild(drawNode);
            
              }
       else if ((locx  != 352 )&&(locx  > 240 )&&(locy == 62)) {
           cherrySprite->setPosition(Point(240,62));
           drawNode = DrawNode::create();
           int i =0 ;
           for (i=305; i  >240;i--){
                drawNode->drawPoint(Point(i,51),123.0f, Color4F ::GREEN);
               
           }
           this->addChild(drawNode);
       }
       else if ((locx  > 171 )&&(locy == 149)) {
           cherrySprite->setPosition(Point(171,149));
           drawNode = DrawNode::create();
           int i =0 ;
           for (i=240; i  >169;i--){
               drawNode->drawPoint(Point(i,137),116.0f, Color4F ::GREEN);
               
           }
           this->addChild(drawNode);
       }
            if ((locx  != 352 )&&(locx  > 131 )&&(locy == 285)) {
                cherrySprite->setPosition(Point(130,285));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=170; i  >129;i--){
                    drawNode->drawPoint(Point(i,273),116.0f, Color4F ::GREEN);
                    
                }
                this->addChild(drawNode);
            
              }
            else if ((locx  <  130)&&(locy ==285) ){
                cherrySprite->setPosition(Point(130,285));
                   
                  }
            else if ((locx  >274)&&(locy ==237) ){
                cherrySprite->setPosition(Point(274,237));
                   
                  }
       
        break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        if (    (locx  <  193 )&&(locy ==90)    ) {
            cherrySprite->setPosition(Point(193,90));
            drawNode = DrawNode::create();
            int i =0 ;
            for (i=132; i <192;i++){
            drawNode->drawPoint(Point(i,75),132.0f, Color4F ::GREEN);
                j++ ;
            }
            this->addChild(drawNode);
//            auto action = MoveTo::create(2, Point(180, 300));
//            melon->runAction(action);
       
          }
        else if ((locx  <  193)&&(locy ==62)) {
            cherrySprite->setPosition(Point(193,62));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=132; i <193;i++){
                drawNode->drawPoint(Point(i,51),132.0f, Color4F ::GREEN);
                }
                this->addChild(drawNode);
         
              }
            
        else if ((locx  <  305)&&(locy ==203) ){
            cherrySprite->setPosition(Point(305,203));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=132; i <305;i++){
                drawNode->drawPoint(Point(i,190),123.0f, Color4F ::GREEN);
                }
                this->addChild(drawNode);
         
              }
            
        else if ((locx  <  305)&&(locy ==62)&&(locx >= 240) ){
            cherrySprite->setPosition(Point(305,62 ));
            
              }
        else if ((locx  <  240)&&(locy ==149)) {
            cherrySprite->setPosition(Point(240,149));
               
              }
            

        else if ((locx  <  274)&&(locy ==285) ){
            cherrySprite->setPosition(Point(274,285));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=170; i <275;i++){
                drawNode->drawPoint(Point(i,274),116.0f, Color4F ::GREEN);
                }
                this->addChild(drawNode);
         
              }
        else if ((locx  <  352)&&(locy ==237) ){
            cherrySprite->setPosition(Point(352,237));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=280; i <353;i++){
                drawNode->drawPoint(Point(i,225),115.0f, Color4F ::GREEN);
                }
                this->addChild(drawNode);
         
              }
        break;
    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            if ((locx  == 131 )&&(locy > 62)) {
               cherrySprite->setPosition(Point(131,62));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=75; i  >51;i--){
                drawNode->drawPoint(Point(132,i),132.0f, Color4F ::GREEN);
                    j++ ;
                }
             
                this->addChild(drawNode);
                auto action = MoveTo::create(0.01, Point(240, 300));
         
             
              }
            if ((locx  == 352 )&&(locy > 62)) {
               cherrySprite->setPosition(Point(352,62));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=199; i  >50;i--){
                drawNode->drawPoint(Point(353,i),114.0f, Color4F ::GREEN);
                    j++ ;
                }
             
                this->addChild(drawNode);
                auto action = MoveTo::create(0.01, Point(240, 300));
         
             
              }
            
            else if ( (locx  == 193)&&(locy > 62)){
           cherrySprite->setPosition(Point(193,62));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=75; i  > 51;i--){
                drawNode->drawPoint(Point(193,i),132.0f, Color4F ::GREEN);
                }
                this->addChild(drawNode);
              
            }
            else if ((locx  ==305)&&(locy >62)) {
               cherrySprite->setPosition(Point(305,62));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=190; i >50;i--){
                drawNode->drawPoint(Point(306,i),115.0f, Color4F ::GREEN);
                 }
                this->addChild(drawNode);
              }
            else if ((locx  ==240)&&(locy >62)) {
               cherrySprite->setPosition(Point(240,62));
               
              }
            else if ((locx  ==171)&&(locy >149)) {
               cherrySprite->setPosition(Point(171,149));
                drawNode = DrawNode::create();}
           
            else if ( (locx  == 130)&&(locy >257 )){
           cherrySprite->setPosition(Point(130,257));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=270; i  > 244;i--){
                drawNode->drawPoint(Point(130,i),115.0f, Color4F ::GREEN);
                }
                this->addChild(drawNode);
              
            }
            else if ( (locx  == 274)&&(locy > 237)){
           cherrySprite->setPosition(Point(275,237));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=270; i  > 224;i--){
                drawNode->drawPoint(Point(275,i),113.0f, Color4F ::GREEN);
                }
                this->addChild(drawNode);
              
            }
            
            break;
    case EventKeyboard::KeyCode::KEY_UP_ARROW:
     
            if ((locx  ==193 )&&(locy < 90)) {
               cherrySprite->setPosition(Point(193,90));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=51; i <74;i++){
                drawNode->drawPoint(Point(193,i),131.0f, Color4F ::GREEN);
                    j++ ;
                }
                this->addChild(drawNode);
                auto action = MoveTo::create(2, Point(200, 300));
//                melon->runAction(action);
             
              }
            else if ((locx  ==352 )&&(locy < 285)) {
               cherrySprite->setPosition(Point(352,285));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=235; i <275;i++){
                drawNode->drawPoint(Point(353,i),114.0f, Color4F ::GREEN);
                 }
                this->addChild(drawNode);
              }
            else if ((locx  ==131 )&&(locy < 203)) {
               cherrySprite->setPosition(Point(131,203));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=80; i <190;i++){
                drawNode->drawPoint(Point(131,i),120.0f, Color4F ::GREEN);
                 }
                this->addChild(drawNode);
              }
            else if ((locx  ==305 )&&(locy < 203)) {
                cherrySprite->setPosition(Point(305,203));
        
              }
            else if ((locx  ==240 )&&(locy < 149)) {
               cherrySprite->setPosition(Point(240,149));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=51; i <137;i++){
                drawNode->drawPoint(Point(240,i),120.0f, Color4F ::GREEN);
                 }
                this->addChild(drawNode);
              }
            else if ((locx  ==305 )&&(locy < 203)) {
                cherrySprite->setPosition(Point(305,203));
        
              }
            else if ((locx  ==171 )&&(locy < 285)) {
               cherrySprite->setPosition(Point(171,285));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=145; i <274;i++){
                drawNode->drawPoint(Point(170,i),116.0f, Color4F ::GREEN);
                 }
                this->addChild(drawNode);
              }
            else if ((locx  ==130 )&&(locy < 285)) {
                cherrySprite->setPosition(Point(130,285));
                
            }
            break;

    default:
    
        break;

            
 
    }
}
 
