

#ifndef __PARAMETERSMENU_SCENE_H__
#define __PARAMETERSMENU_SCENE_H__

#include "cocos2d.h"

class ParametersMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(ParametersMenu);
    void GoHome(Ref *pSender); //will be called when the player clicks on the resume button from the Pause scene to pop the Pause scene off the stack
    void Music(Ref *pSender); // will be called when the player clicks on the main menu button from the Pause scene to replace the current scene with the Main Menu scene while popping all the scenes off the stack
    void Mute(Ref *pSender); //will be called when the player clicks on the retry button from the Pause scene to replace the current scene with the Game scene while popping all the scenes off the stack.
    void GoBack (Ref *pSpender);

};
#endif // __PAUSEMENU_SCENE_H__
