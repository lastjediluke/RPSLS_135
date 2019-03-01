#include <iostream>
#include <string>
#include <stdio.h>   
#include "Hands.h"  



void Hands::setHand(char h)
{
    // std::cout << "Setting hand..." << std::endl;
    switch(h)
    {
        case 'r' : myHand = rock; std::cout << "You picked Rock!" <<std::endl; break;
        case 'p' : myHand = paper; std::cout << "You picked Paper!" <<std::endl; break;
        case 's' : myHand = scissors; std::cout << "You picked Scissors!" <<std::endl; break;
        case 'l' : myHand = lizard; std::cout << "You picked Lizard!" <<std::endl; break;
        case 'v' : myHand = spock; std::cout << "You picked Spock!" <<std::endl; break;
        default: std::cout << "Sorry, that is not a hand" <<std::endl;
    }
}

bool Hands::isHand(char key)
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

handType getWinner(handType a, handType b)
{
}

bool initWinnerMap()
{

}

// using namespace std;
// cout << "Computer uses " << computerHand << "!\n";
//   if((playerHand == "rock" && (computerHand == "scissors" || computerHand == "lizard")) || (playerHand == "paper" && (computerHand == "rock" || computerHand == "spock")) || (playerHand == "scissors" && (computerHand == "paper" || computerHand == "lizard")) || (playerHand == "lizard" && (computerHand == "spock" || computerHand == "paper")) || (playerHand == "spock" && (computerHand == "rock" || computerHand == "scissors")))
//   {
//       cout << "Player Wins!" << endl;
//   }
//   else if(playerHand == computerHand)
//   {
//       cout << "It's a Tie!" << endl;
//   }
//   else if((computerHand == "rock" && (playerHand == "scissors" || playerHand == "lizard")) || (computerHand == "paper" && (playerHand == "rock" || playerHand == "spock")) || (computerHand == "scissors" && (playerHand == "paper" || playerHand == "lizard")) || (computerHand == "lizard" && (playerHand == "spock" || playerHand == "paper")) || (computerHand == "spock" && (playerHand == "rock" || playerHand == "scissors")))
//   {
//       cout << "Computer Wins!" << endl;
//   }
//   else
//   {
//       cout << "Incorrect input" << endl;
//   }