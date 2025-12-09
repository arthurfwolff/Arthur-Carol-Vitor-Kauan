#ifndef WALLFOLLOWERTHREAD_H
#define WALLFOLLOWERTHREAD_H

#include "Aria.h"
#include "ClassRobo.h"

class WallFollowerThread : public ArASyncTask
{
public:
    WallFollowerThread(PioneerRobot *_robo);
    virtual void *runThread(void *);

    void waitOnCondition();
    void lockMutex();
    void unlockMutex();

private:
    PioneerRobot *robo;
    int sonar[8];
    int parede_direita; 

    float Proporcional(float erro, float pGain);
    void seguirParedeDSImples();
    void seguirParedeDComP();
};

#endif 