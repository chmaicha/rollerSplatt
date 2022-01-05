//
//  START2.h
//  namegame
//
//  Created by Mac_HD on 4/1/2022.
//

#ifndef START2_h
#define START2_h

class level2 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(level2);
    void GoToGameOverScene(Ref *pSender);
};

#endif /* START2_h */
