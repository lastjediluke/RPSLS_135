#include <iostream>
#include <string>
#include <stdio.h>   
#include "Hands.h"  



void Hands::setHand(char h)
{
    // std::cout << "Setting hand..." << std::endl;
    switch(h)
    {
        case 'r' : myHand = rock; std::cout << "Rock!" <<std::endl; break;
        case 'p' : myHand = paper; std::cout << "Paper!" <<std::endl; break;
        case 's' : myHand = scissors; std::cout << "Scissors!" <<std::endl; break;
        // case 'l' : myHand = lizard; std::cout << "Lizard!" <<std::endl; break;
        // case 'v' : myHand = spock; std::cout << "Spock!" <<std::endl; break;
        default: std::cout << "Sorry, that is not a hand" <<std::endl;
    }
}

bool Hands::isHand(char key)
{
    // std::cout << "Validating Hand..." << std::endl;
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

Hands::handType Hands::getWinner(handType a, handType b)
{
    handType winner;
    if (a == b)
    {
        // std::cout << "we found a tie" << std::endl;
        winner = tie;
        return winner;
    }

    switch(a)
    {
        case rock:
        {
            if (b == scissors || b == lizard) { winner = a; break; }
            else { winner = b; break; }
        }
        case paper:
        {
            if (b == rock || b == spock) { winner = a; break; }
            else { winner = b; break; }
        }
        case scissors:
        {
            if (b == paper || b == lizard) { winner = a; break; }
            else { winner = b; break; }
        }
        case lizard:
        {
            if (b == paper || b == spock) { winner = a; break; }
            else { winner = b; break; }
        }
        case spock:
        {
            if (b == rock || b == scissors) { winner = a; break; }
            else { winner = b; break; }
        }
        case tie:
        {
            break;
        }
    }
    return winner;
}
