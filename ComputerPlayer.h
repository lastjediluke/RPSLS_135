#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include "Hands.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <sstream>
#include "Chooser.h"
#include "ChooserFactory.h"

class ComputerPlayer
{
public:
    ComputerPlayer(char randOrSmart);

    char setHand(std::string s, int patternLen, char difficulty);
    Hands::handType getHand() { return cpuHand.getHand(); }
    void setScore(int sc);
    void getScore();

    // new funcs for Assignment 4
    void insertNewPattern(std::string s);
    void increasePatternFreq(std::string s);
    void toTextFile(std::string s);
    int strToInt(std::string line);
private:
    int wins;
    int losses;
    int ties;
    Hands cpuHand;
    Chooser *chooser;
};




#endif