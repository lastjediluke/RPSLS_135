#include "HumanPlayer.h"

void HumanPlayer::setHand(char pickHand)
{
    // calls setHand() within the Hands class
    playerHand.setHand(pickHand);
}

bool HumanPlayer::isHand(char key)
{
    return playerHand.isHand(key);
}

void HumanPlayer::getScore()
{
    std::cout << "Your Wins: " << wins << "; Losses: " << losses << "; Ties " << ties << std::endl;
}

int HumanPlayer::setScore(int sc)
{
    switch (sc)
    {
        case 0: ties++; break;
        case 1: wins++; break;
        case -1: losses++; break;
    }
}