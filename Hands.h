#ifndef HANDS_H_
#define HANDS_H_

#include <iostream>

class Hands 
{
public:
    enum handType
    {
        rock,
        paper,
        scissors,
        lizard,
        spock
    };
    
private:
    handType myHand;

public:
    Hands(){}
    handType getWinner(handType a, handType b){}
    void setHand(char h)
    {
        std::cout << "Setting hand..." << std::endl;
        switch(h)
        {
            case 'r' : myHand = rock; std::cout << "You picked Rock!" <<std::endl; break;
            case 'p' : myHand = paper; std::cout << "You picked Paper!" <<std::endl; break;
            case 's' : myHand = scissors; std::cout << "You picked Scissors!" <<std::endl; break;
            default: std::cout << "Sorry, that is not a hand" <<std::endl;
        }
    }
    bool isHand(char key)
    {
        std::cout << "Validating Hand..." << std::endl;
        bool valid = false;
        switch(key)
        {
            case 'r' : valid = true; break;
            case 'p' : valid = true; break;
            case 's' : valid = true; break;
            default: std::cout << "Sorry, that is not a hand" << std::endl; valid = false;
        } 
        return valid;
    }

};

#endif


