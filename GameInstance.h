#ifndef GAMEINSTANCE_H_
#define GAMEINSTANCE_H_

#include <iostream>
#include "HumanPlayer.h"
#include "ComputerPlayer.h"


class GameInstance
{
public:
    GameInstance();
    static void startGameLoop();
private:
    ComputerPlayer *cpu;
    HumanPlayer *myPlayer;


};




#endif