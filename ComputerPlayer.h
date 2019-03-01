#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include "Hands.h"
#include <stdlib.h>
#include <time.h>

class ComputerPlayer
{
public:
    ComputerPlayer();

    void setHand();
private:
    int wins;
    int losses;
    int ties;
    Hands cpuHand;
};




#endif