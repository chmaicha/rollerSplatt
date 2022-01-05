
#ifndef start1_h
#define start1_h

#include "cocos2d.h"

class level1 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(level1);
    void GoToGameScen(Ref *pSender);
};
#endif /* start1_h */
