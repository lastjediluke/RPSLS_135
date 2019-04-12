#ifndef GAMEINSTANCE_H_
#define GAMEINSTANCE_H_

#include <iostream>
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <string>
#include "Hands.h"
#include <fstream>



<<<<<<< HEAD

=======
// Long
// int roundMax = 0;
>>>>>>> f1ea0d948d4923bcdf0a934143981ead2314133e
class GameInstance
{

public:
    GameInstance();
    void startGameLoop();
    void printInstructions();
    void setCpu(char choice);
    bool isValidHand(char key);
    char updateScore(Hands::handType winner);
<<<<<<< HEAD
    int getRoundMax()       { return roundMax;      }
    void setRoundMax(int x){ roundMax = x;         }  
=======
    

    // Long
    void setRoundMax(int x)  { roundMax = x;     }  
    int getRoundMax()               { return roundMax;  }

>>>>>>> f1ea0d948d4923bcdf0a934143981ead2314133e
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

    int roundMax;

    
private:
    ComputerPlayer *cpu;
    HumanPlayer *myPlayer;
    int roundCount;
    int gameCount;
<<<<<<< HEAD
    int roundMax;
=======

    

    
>>>>>>> f1ea0d948d4923bcdf0a934143981ead2314133e
    
};




#endif