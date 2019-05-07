#ifndef HANDS_H_
#define HANDS_H_

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <string>
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
    static Hand *make_hand(std::string);
    // bool initWinnerMap();
    
};

#endif


class Rock: public Hands
{
public:
	string handType = "rock";
	std::string beats[] = {"scissors", "lizard"};
}

class Paper: public Hands
{
public:
	string handType = "paper";
	std::string beats[] = {"rock", "spock"};
}

class Scissors: public Hands
{
public:
	string handType = "scissors";
	std::string beats[] = {"paper", "lizard"};
}

class Lizard: public Hands
{
public:
	string handType = "lizard";
	std::string beats[] = {"spock", "paper"};
}

class Spock: public Hands
{
public:
	string handType = "spock";
	std::string beats[] = {"scissors", "rock"};
}


// std::multimap<handType, handType> winnersMap =
// {
// 		{scissors, lizard},
// 		{rock, spock},
//         {scissors, lizard},
//         {scissors, lizard},
//         {scissors, lizard},
// };

// vector<int> vect1{ 10, 20, 30 }; 