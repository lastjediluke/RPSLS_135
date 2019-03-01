#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer()
{
    wins = 0;
    losses = 0;
    ties = 0;
}

void ComputerPlayer::setHand()
{
    // set random hand
    srand ( time(NULL) ); //initialize the random seed
    const char arrayNum[5] = {'r', 'p', 's', 'l', 'v'};
    int RandIndex = rand() % 5; //generates a random number between 0 and 4
    std::cout << "CPU picked " << arrayNum[RandIndex] << std::endl;
    cpuHand.setHand(arrayNum[RandIndex]);
}

