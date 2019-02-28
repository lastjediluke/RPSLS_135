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