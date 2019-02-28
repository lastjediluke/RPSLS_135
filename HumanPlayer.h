#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include <iostream>
#include "Hands.h"

class HumanPlayer
{
public:
    HumanPlayer()
    {
        // wins = 0;
        // losses = 0;
        // ties = 0;
        std::cout << "Human Player initialized" <<std::endl;
    }
    bool isHand(char key);
    void setHand(char pickHand);
private:
    int wins;
    int losses;
    int ties;
    Hands playerHand;
};




#endif