#include "HumanPlayer.h"

HumanPlayer::HumanPlayer()
{
    wins = 0;
    losses = 0;
    ties = 0;
    std::cout << "Human Player initialized" << std::endl;
}

char HumanPlayer::setHand(char pickHand)
{
    // calls setHand() within the Hands class
    playerHand.setHand(pickHand);
    return pickHand;
}

bool HumanPlayer::isHand(char key)
{
    return playerHand.isHand(key);
}

void HumanPlayer::getScore()
{
    std::cout << "Your Wins: " << wins << "; Losses: " << losses << "; Ties: " << ties << std::endl;
}

void HumanPlayer::setScore(int sc)
{
    switch (sc)
    {
        case 0: ties++; break;
        case 1: wins++; break;
        case -1: losses++; break;
    }
}