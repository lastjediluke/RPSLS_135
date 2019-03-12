#ifndef GAMEINSTANCE_H_
#define GAMEINSTANCE_H_

#include <iostream>
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <string>
#include "Hands.h"
#include <fstream>


class GameInstance
{
public:
    GameInstance();
    void startGameLoop();
    void printInstructions();
    bool isValidHand(char key);
    void updateScore(Hands::handType winner);
    int getRoundCount()     { return roundCount;    }
    int getGameCount()      { return gameCount;     }
    int incRoundCount()     { return roundCount++;  }
    int incGameCount()      { return gameCount++;   }
    int resetRoundCount()   { roundCount = 0; return roundCount; }
    std::string recordHand(char a, int patternSize);
    std::string pattern;
private:
    ComputerPlayer *cpu;
    HumanPlayer *myPlayer;
    int roundCount;
    int gameCount;
};




#endif