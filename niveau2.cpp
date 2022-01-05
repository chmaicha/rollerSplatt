#include "/Users/mac_hd/Desktop/namegame/Classes/niveau2.h"
 // used to include the GameScen so that the scene can be accessed
#include "/Users/mac_hd/Desktop/namegame/Classes/MainMenu.h" // used to include the HelloWorldScene so that the scene can be accessed
#include "/Users/mac_hd/Desktop/namegame/Classes/ParametersScreen.h"
#include "/Users/mac_hd/Desktop/namegame/Classes/START3.h"
USING_NS_CC;

Scene* niveau2::createScene()
{
 //scene is an autorelease object
    auto scene = Scene::create();
    //scene is an autorelease object
    auto Layer = niveau2::create();
    //add layer as a child to scene 
    scene->addChild(Layer);
    //return the scene
    return scene;
}
// on "init": initialisation of the instances
bool niveau2::init()
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
                                        "/Users/mac_hd/Desktop/namegame/Resources/images/settings.png",
                                           CC_CALLBACK_1(niveau2::GoToParamatersScene, this));
      parameters->setPosition(Point(parameters->getContentSize().width -
      (parameters->getContentSize().width / 2) + origin.x,
      visibleSize.height - parameters->getContentSize().height +
      (parameters->getContentSize().width / 2) + origin.y));
      auto menu = Menu::create(parameters, NULL);
      menu->setPosition(Point::ZERO);
      this->addChild(menu);
  
    auto backgroundSprite = Sprite::create("/Users/mac_hd/Desktop/namegame/Resources/images/thumb2-orange-abstract-background-orange-geometric-background-orange-creative-background-orange-paper-background.jpg");
       backgroundSprite->setPosition(Point((visibleSize.width / 2) +origin.x, (visibleSize.height / 2) + origin.y));
       this->addChild(backgroundSprite, -1);
    auto plan = Sprite::create("/Users/mac_hd/Desktop/namegame/Resources/images/Sans titre-6.png");
   plan->setPosition(Point((visibleSize.width / 2) +origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(plan,0 );
   orangeSprite = Sprite::create("/Users/mac_hd/Desktop/namegame/Resources/images/orange-set-drawn-cute-kawaii-food-faces-orange-cute-kawaii-mascot-set-of-funny-kawaii-drawn-fruit-eps-vector_csp69835889.jpg-modified.png");
       orangeSprite->setPosition(Point(361,93));
        this->addChild(orangeSprite, 2);
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
     
    auto nextlevel =MenuItemImage::create("/Users/mac_hd/Desktop/namegame/Resources/images/Sans titre-8.png",
                                         "/Users/mac_hd/Desktop/namegame/Resources/images/Sans titre-8.png",
                                           CC_CALLBACK_1(niveau2::GoToStart3, this));//The number 1 at the end of CC_CALLBACK_1 specifies how many parameters the function that is being called takes

    auto menu1 = Menu::create( nextlevel, NULL); //creates a menu with the Menu items.
    menu1->alignItemsHorizontally();
    menu1->setPosition(Point(450,45));
    this->addChild(menu1);
    
    return true;
}

void niveau2::GoToStart3(cocos2d::Ref *pSender)
{

    auto scene = level3::createScene();
    Director::getInstance()->replaceScene( (TransitionFade::create(1, scene, Color3B(255,255,255))));
}

void niveau2::GoToParamatersScene(cocos2d::Ref *pSender)
{
    //GoToPauseScene function first creates a local scene instance of the Pause scene and then pushes it onto the stack.
    auto scene = ParametersMenu::createScene();
    Director::getInstance()->replaceScene( (TransitionFade::create(1, scene, Color3B(255,255,255))));
}


void niveau2::update(float delta) {
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
bool niveau2::isKeyPressed(EventKeyboard::KeyCode keyCode) {
    if (keys[keyCode]) {
        return true;
    }
    else {
        return false;
    }
    
}



void niveau2::keyPressedDuration(EventKeyboard::KeyCode code) {


    float locx = orangeSprite->getPositionX();
    float locy = orangeSprite->getPositionY();
    static int j =0 ;
    
    switch (code)
    {
       
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        
            if ((locx  > 166 )&&(locy == 156)) {
          orangeSprite->setPosition(Point(166,156));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=361; i  >166;i--){
                    drawNode->drawPoint(Point(i,156),132.0f, Color4F ::RED);
                    
                }
                this->addChild(drawNode);
            
              }
            else if ((locx  > 292 )&&(locy == 93)) {
                orangeSprite->setPosition(Point(292,93));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=361; i  >292;i--){
                drawNode->drawPoint(Point(i,93),132.0f, Color4F ::RED);
                    j++ ;
                    
                }
                this->addChild(drawNode);
//                auto action = MoveTo::create(2, Point(230, 300));
//                melon->runAction(action);
           
              }
            if ((locx  > 292 )&&(locy == 213)) {
          orangeSprite->setPosition(Point(292,213));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=361; i  >292;i--){
                    drawNode->drawPoint(Point(i,213),132.0f, Color4F ::RED);
                    
                }
                this->addChild(drawNode);
            
              }
   
        break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        if (   (    locx  >= 292) && (locx  <  361 )&&(locy ==93)    ) {
            orangeSprite->setPosition(Point(361,93));
            drawNode = DrawNode::create();
            int i =0 ;
            for (i=292; i <361;i++){
            drawNode->drawPoint(Point(i,93),132.0f, Color4F ::RED);
                j++ ;
            }
            this->addChild(drawNode);
//            auto action = MoveTo::create(2, Point(180, 300));
//            melon->runAction(action);
       
          }
        else if ((locx  <  361)&&(locy ==213)) {
            orangeSprite->setPosition(Point(361,213));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=292; i <362;i++){
                drawNode->drawPoint(Point(i,211),132.0f, Color4F ::RED);
                }
                this->addChild(drawNode);
         
              }
            
        else if ((locx  <  361)&&(locy ==156) ){
            orangeSprite->setPosition(Point(361,156));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=165; i <361;i++){
                drawNode->drawPoint(Point(i,156),132.0f, Color4F ::RED);
                }
                this->addChild(drawNode);
         
              }
            
        break;
    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            if ((locx  == 166 )&&(locy > 93)) {
                orangeSprite->setPosition(Point(166,93));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=156; i  >93;i--){
                drawNode->drawPoint(Point(166,i),132.0f, Color4F ::RED);
                    j++ ;
                }
             
                this->addChild(drawNode);
                auto action = MoveTo::create(0.01, Point(240, 300));
         
             
              }
            
            else if ( (locx  == 361)&&(locy > 93)){
                orangeSprite->setPosition(Point(361,93));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=156; i  > 93;i--){
                drawNode->drawPoint(Point(361,i),132.0f, Color4F ::RED);
                }
                this->addChild(drawNode);
              
            }
            else if ((locx  ==292)&&(locy >93)) {
                orangeSprite->setPosition(Point(292,93));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=213; i >93;i--){
                drawNode->drawPoint(Point(292,i),132.0f, Color4F ::RED);
                 }
                this->addChild(drawNode);
              }
            break;
    case EventKeyboard::KeyCode::KEY_UP_ARROW:
     
            if ((locx  ==361 )&&(locy < 156)) {
                orangeSprite->setPosition(Point(361,156));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=92; i <156;i++){
                drawNode->drawPoint(Point(361,i),132.0f, Color4F ::RED);
                    j++ ;
                }
                this->addChild(drawNode);
                auto action = MoveTo::create(2, Point(200, 300));

             
              }
            else if ((locx  ==166 )&&(locy < 213)) {
                orangeSprite->setPosition(Point(166,213));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=93; i <213;i++){
                drawNode->drawPoint(Point(166,i),132.0f, Color4F ::RED);
                 }
                this->addChild(drawNode);
              }
            else if ((locx  ==292 )&&(locy < 213)) {
                orangeSprite->setPosition(Point(292,213));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=93; i <211;i++){
                drawNode->drawPoint(Point(292,i),132.0f, Color4F ::RED);
                 }
                this->addChild(drawNode);
              }
            break;

    default:
    
        break;

            
 
    }
}
 
