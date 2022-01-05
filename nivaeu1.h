
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class GameScreen : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    void update(float delta) override;
    virtual bool init();
    cocos2d::Sprite* playerSprite;
    cocos2d::DrawNode* drawNode;

// here is a difference. Methode 'init' in cocos2d-x returns bool, instead of 'id'

    // implement the "static create()" method manually
    CREATE_FUNC(GameScreen);
    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);

        void keyPressedDuration(cocos2d::EventKeyboard::KeyCode code);
        std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;

    void GoToParamatersScene(Ref *pSender);//will be called when the player clicks on the pause button in the Game scene to push the Pause scene onto the stack
    void GoTostatrt2(Ref *pSender); //will be called when the player dies to replace the Game scene with the Game Over scene


};
#endif // __GAME_SCENE_H__

