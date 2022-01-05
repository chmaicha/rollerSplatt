//
//  START3.h
//  namegame
//
//  Created by Mac_HD on 4/1/2022.
//

#ifndef START3_h
#define START3_h

class level3 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(level3);
    void GoTolevel3(Ref *pSender);
};

#endif /* START3_h */
