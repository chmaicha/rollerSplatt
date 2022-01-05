#include "/Users/mac_hd/Desktop/namegame/Classes/nivaeu1.h"
#include "/Users/mac_hd/Desktop/namegame/Classes/ParametersScreen.h"  //include the Pause and Game Over scenes so that the scenes can be accessed
#include "/Users/mac_hd/Desktop/namegame/Classes/START2.h"

USING_NS_CC;


Scene* GameScreen::createScene()
{
 //scene is an autorelease object
    auto scene = Scene::create();

    //scene is an autorelease object
    auto Layer = GameScreen::create();

    //add layer as a child to scene
    scene->addChild(Layer);
    //return the scene
    return scene;
}
// on "init": initialisation of the instances
bool GameScreen::init()
{
    

    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

  Size visibleSize = Director::getInstance()->getVisibleSize();
  Point origin = Director::getInstance()->getVisibleOrigin();
    auto nextlevel =MenuItemImage::create("/Users/mac_hd/Desktop/namegame/Resources/images/Sans titre-8.png",
                                         "/Users/mac_hd/Desktop/namegame/Resources/images/Sans titre-8.png",
                                           CC_CALLBACK_1(GameScreen::GoTostatrt2, this));//The number 1 at the end of CC_CALLBACK_1 specifies how many parameters the function that is being called takes

    auto menu1 = Menu::create( nextlevel, NULL); //creates a menu with the Menu items.
    menu1->alignItemsHorizontally();
    menu1->setPosition(Point(450,45));
    this->addChild(menu1);
    auto parameters =
      MenuItemImage::create("/Users/mac_hd/Desktop/namegame/Resources/images/settings.png",
      "/Users/mac_hd/Desktop/namegame/Resources/images/settings.png",
      CC_CALLBACK_1(GameScreen::GoToParamatersScene, this));
      parameters->setPosition(Point(parameters->getContentSize().width -
      (parameters->getContentSize().width / 2) + origin.x,
      visibleSize.height - parameters->getContentSize().height +
      (parameters->getContentSize().width / 2) + origin.y));
      auto menu = Menu::create(parameters, NULL);
      menu->setPosition(Point::ZERO);
      this->addChild(menu);
    
    auto backgroundSprite = Sprite::create("/Users/mac_hd/Desktop/namegame/Resources/images/1.png");
        
    backgroundSprite->setPosition(Point((visibleSize.width/2 ) , (visibleSize.height/2) ));
     // sets the position of the background sprite at the center ofthe screen using the visible size, which is the area of the screen that is available ona particular device, as there are different screen sizes
 
    this->addChild(backgroundSprite, -1);
    
    this->scheduleUpdate();

playerSprite = Sprite::create("/Users/mac_hd/Desktop/namegame/Resources/images/cartoon-watermelon-fruit-character-vector-18357288-modified-2.png");
    playerSprite->setPosition(Point(115,56));
    this->addChild(playerSprite, 2);
    //EventListenerKeyboard fonctionne juste lorsqu on cliaue sur le clvier
auto listener = EventListenerKeyboard::create();

listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
    keys[keyCode] = true;
};

listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
    keys[keyCode] = false;
};
_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

this->scheduleUpdate();
 //
    return true;
}

void GameScreen::GoTostatrt2(cocos2d::Ref *pSender)
{

    auto scene = level2::createScene();
    Director::getInstance()->replaceScene( (TransitionFade::create(1, scene, Color3B(255,255,255))));
}
void GameScreen::GoToParamatersScene(cocos2d::Ref *pSender)
{
    //GoToParametersScene function first creates a local scene instance of the parameters scene and thenpushes it onto the stack.
    auto scene = ParametersMenu::createScene();
    Director::getInstance()->replaceScene( (TransitionFade::create(1, scene, Color3B(255,255,255))));
}

void GameScreen::update(float delta) {
    Node::update(delta);
    //creation de 4variables qui ne vont fonctionner que si on clique sur les 4 cliques de directions
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
bool GameScreen::isKeyPressed(EventKeyboard::KeyCode keyCode) {
    if (keys[keyCode]) {
        return true;
    }
    else {
        return false;
    }
}
void GameScreen::keyPressedDuration(EventKeyboard::KeyCode code) {
    float locx = playerSprite->getPositionX();
    float locy = playerSprite->getPositionY();
    static int j =0 ;
    switch (code)
    {
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            //si le joueur clique sur le boutton gauche du clavier il ya plusieur possibiltes de mouvement sur l axe des x a gauche , ces possibiltes dependent de la position innitiale de la balle
            if ((locx  > 115 )&&(locy == 56)) {
                playerSprite->setPosition(Point(115,56));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=367; i  >115;i--){
 //cette fonction coclorie le chemin passe par la balle point par point d'une maniere continue commencant par le point de depart vers le point destination de le balle 
                drawNode->drawPoint(Point(i,56),180.0f, Color4F::MAGENTA);
                    
                }
                this->addChild(drawNode);
            
              }
            else if ((locx  > 115 )&&(locy == 254)) {
                playerSprite->setPosition(Point(115,254));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=367; i  >115;i--){
                drawNode->drawPoint(Point(i,254),180.0f, Color4F ::MAGENTA);
                    j++ ;
                    
                }
                this->addChild(drawNode);
    
           
              }
   
        break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            //si le joueur clique sur le boutton droit du clavier il ya plusieur possibiltes de mouvement sur l axe des x a droit , ces possibiltes dependent de la position innitiale de la balle
        if ((locx  <  367)&&(locy ==56)) {
            playerSprite->setPosition(Point(367,56));
        
            drawNode = DrawNode::create();
            int i =0 ;
            for (i=115; i <367;i++){
                
            drawNode->drawPoint(Point(i,56),180.0f, Color4F ::MAGENTA);
              
            }
            this->addChild(drawNode);
   
       
          }
        else if ((locx  <  335.01)&&(locy ==254)) {
                playerSprite->setPosition(Point(367,254));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=115; i <367;i++){
                drawNode->drawPoint(Point(i,254),180.0f, Color4F ::MAGENTA);
                }
                this->addChild(drawNode);
         
              }
            
        break;
    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            //si le joueur clique sur le boutton down du clavier il ya plusieur possibiltes de mouvement sur l axe des y vers le bas , ces possibiltes dependent de la position innitiale de la balle
            if ((locx  == 115 )&&(locy > 56)) {
                playerSprite->setPosition(Point(115,56));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=254; i  >56;i--){
                drawNode->drawPoint(Point(115,i),180.0f, Color4F ::MAGENTA);
                 
                  
                }
             
                this->addChild(drawNode);
         
                
              }
            
            else if ( (locx  == 367 )&&(locy > 56)){
                playerSprite->setPosition(Point(367,56));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=254; i  > 56;i--){
                
                drawNode->drawPoint(Point(367,i),180.0f, Color4F ::MAGENTA);
                }
                this->addChild(drawNode);
              
            }
            break;
    case EventKeyboard::KeyCode::KEY_UP_ARROW:
            //si le joueur clique sur le boutton up du clavier il ya plusieur possibiltes de mouvement sur l axe des y vers le haut , ces possibiltes dependent de la position innitiale de la balle

            if ((locx  ==367 )&&(locy < 254)) {
                playerSprite->setPosition(Point(367,254));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=56; i <254;i++){
                drawNode->drawPoint(Point(367,i),180.0f, Color4F ::MAGENTA);
                   
                }
                this->addChild(drawNode);
            
             
              }
            else if ((locx  ==115 )&&(locy < 254)) {
                playerSprite->setPosition(Point(115,254));
                drawNode = DrawNode::create();
                int i =0 ;
                for (i=56; i <254;i++){
                drawNode->drawPoint(Point(115,i),180.0f, Color4F ::MAGENTA);
                 }
                this->addChild(drawNode);
              }
            break;

    default:
    
        break;

            
 
    }
}
