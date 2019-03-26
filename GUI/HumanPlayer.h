#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include <iostream>
#include "Hands.h"

class HumanPlayer
{
public:
    HumanPlayer();
    bool isHand(char key);
    char setHand(char pickHand);
    void setScore(int sc);
    void getScore();
    Hands::handType getHand() { return playerHand.getHand(); }
private:
    int wins;
    int losses;
    int ties;
    Hands playerHand;
};




#endif