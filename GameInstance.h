#ifndef GAMEINSTANCE_H_
#define GAMEINSTANCE_H_

#include <iostream>
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <string>


class GameInstance
{
public:
    GameInstance();
    void startGameLoop();
    bool isValidHand(char key);
private:
    ComputerPlayer *cpu;
    HumanPlayer *myPlayer;


};




#endif