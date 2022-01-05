//
//  niveau3.h
//  namegame
//
//  Created by Mac_HD on 4/1/2022.
//

#ifndef niveau3_h
#define niveau3_h

#include "cocos2d.h"

class niveau3 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    void update(float delta) override;
    virtual bool init();
    cocos2d::Sprite* cherrySprite;
    cocos2d::DrawNode* drawNode;
    // implement the "static create()" method manually
    CREATE_FUNC(niveau3);
  
    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);
void keyPressedDuration(cocos2d::EventKeyboard::KeyCode code);
        std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
    void GoToParamatersScene(Ref *pSender);
};


#endif /* niveau3_h */
