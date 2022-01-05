

#ifndef __GAMEOVER_SCENE_H__
#define __GAMEOVER_SCENE_H__

#include "cocos2d.h"

class niveau2 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    void update(float delta) override;
    virtual bool init();
    cocos2d::Sprite* orangeSprite;
    cocos2d::DrawNode* drawNode;
    // implement the "static create()" method manually
    CREATE_FUNC(niveau2);
    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);

        void keyPressedDuration(cocos2d::EventKeyboard::KeyCode code);
        std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
    void GoToParamatersScene(Ref *pSender);
    void GoToStart3(Ref *pSender);
};
#endif // __GAMEOVER_SCENE_H__
