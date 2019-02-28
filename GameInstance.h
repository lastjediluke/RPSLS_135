#ifndef GAMEINSTANCE_H_
#define GAMEINSTANCE_H_

#include <iostream>
#include "HumanPlayer.h"
#include "ComputerPlayer.h"


class GameInstance
{
public:
    GameInstance();
    void startGameLoop();
    bool isValid(char key);
private:
    ComputerPlayer *cpu;
    HumanPlayer *myPlayer;


};




#endif