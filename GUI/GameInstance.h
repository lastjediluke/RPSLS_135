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
    void setCpu(char choice);
    bool isValidHand(char key);
    char updateScore(Hands::handType winner);
    int getRoundCount()     { return roundCount;    }
    int getGameCount()      { return gameCount;     }
    int setRoundCount()     { return roundCount++;  }
    int setGameCount()      { return gameCount++;   }
    int resetRoundCount()   { roundCount = 1; return roundCount; }
    std::string recordHand(char a, int patternSize);
    std::string pattern;

    // Assignment 5 getters
    HumanPlayer *getPlayer()    { return myPlayer;              }
    ComputerPlayer *getCpu()    { return cpu;                   }
    int getComputerWins()       { return cpu->getWins();        }
    int getHumanWins()          { return myPlayer->getWins();   }
    int getTies()               { return myPlayer->getTies();   }
private:
    ComputerPlayer *cpu;
    HumanPlayer *myPlayer;
    int roundCount;
    int gameCount;
    
};




#endif