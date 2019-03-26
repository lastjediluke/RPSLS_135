#ifndef HANDS_H_
#define HANDS_H_

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <map>

class Hands 
{
public:
    enum handType
    {
        rock,
        paper,
        scissors,
        lizard,
        spock,
        tie
    };
    // std::vector<handType> v;
    // std::map < handType, std::vector<handType> > winnersMap;
    
    
private:
    handType myHand;

public:
    Hands(){}
    static handType getWinner(handType a, handType b);
    void setHand(char h);
    bool isHand(char key);
    handType getHand() { return myHand; }
    // bool initWinnerMap();
    
};

#endif


// std::multimap<handType, handType> winnersMap =
// {
// 		{scissors, lizard},
// 		{rock, spock},
//         {scissors, lizard},
//         {scissors, lizard},
//         {scissors, lizard},
// };

// vector<int> vect1{ 10, 20, 30 }; 