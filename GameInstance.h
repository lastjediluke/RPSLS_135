#ifndef GAMEINSTANCE_H_
#define GAMEINSTANCE_H_

#include <iostream>
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <string>
#include "Hands.h"


class GameInstance
{
public:
    GameInstance();
    void startGameLoop();
    bool isValidHand(char key);
    void updateScore(Hands::handType winner);
    int gameCount;
private:
    ComputerPlayer *cpu;
    HumanPlayer *myPlayer;


};




#endif