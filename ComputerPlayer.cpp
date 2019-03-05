#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer()
{
    wins = 0;
    losses = 0;
    ties = 0;
}

void ComputerPlayer::getScore()
{
    std::cout << "CPU Wins: " << wins << "; Losses: " << losses << "; Ties: " << ties << std::endl;
}

char ComputerPlayer::setHand(std::string s)
{
    if (s.length() == 5)
    {
        std::ifstream fin( "ml.txt" );
        std::string line;
        while ( getline( fin, line ) ) 
        {
            if ( line.find( "blah" ) != string::npos ) // if found in line then
            std::cout << "Found \"blah\"" << std::endl; // do something
            std::cout << string::npos
        }

        // find if pattern is in the text file
        // read file into a string 
        // if it is, then use that hand
        // else pick something random
    }

    // else we will pick a random one
    else
    {
        // set random hand
        srand ( time(NULL) ); //initialize the random seed
        const char arrayNum[3] = {'r', 'p', 's'};
        int RandIndex = rand() % 3; //generates a random number between 0 and 4
        // std::cout << "CPU picked " << arrayNum[RandIndex] << std::endl;
        cpuHand.setHand(arrayNum[RandIndex]);
        return arrayNum[RandIndex];
    }
    
}

void ComputerPlayer::setScore(int sc)
{
    switch (sc)
    {
        case 0: ties++; break;
        case 1: wins++; break;
        case -1: losses++; break;
    }
}

