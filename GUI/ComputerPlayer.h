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
    char getPrediction() { return prediction; }
    char setHand(std::string s, int patternLen, char difficulty);
    Hands::handType getHand() { return cpuHand.getHand(); }
    void setScore(int sc);
    void getScore();
    void setPrediction(char c) { prediction = c; }
    int getWins() { return wins; }
    void resetWins() { wins = 0; }

    // new funcs for Assignment 4
    void insertNewPattern(std::string s);
    void increasePatternFreq(std::string s);
    void toTextFile(std::string s);
    int strToInt(std::string line);
    bool getRandFlag() { return randFlag; }
    void makePrediction(std::string s, int patternLen);
private:
    int wins;
    int losses;
    int ties;
    char prediction;
    Hands cpuHand;
    Chooser *chooser;
    bool randFlag;

};




#endif