#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include "Hands.h"
#include <stdlib.h>
#include <time.h>
#include <string>

class ComputerPlayer
{
public:
    ComputerPlayer();

    char setHand(std::string s);
    Hands::handType getHand() { return cpuHand.getHand(); }
    void setScore(int sc);
    void getScore();
private:
    int wins;
    int losses;
    int ties;
    Hands cpuHand;
};




#endif