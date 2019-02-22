#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include <iostream>

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

    // setHand()
private:
    int wins;
    int losses;
    int ties;
    
    // hand
};




#endif