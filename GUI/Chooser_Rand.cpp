   
#include "Chooser_Rand.h"
#include <stdlib.h>
#include <time.h>

char Chooser_Rand::make_choice(std::string s, int patternLen, char p)
{
	// set random hand
    srand ( time(NULL) ); //initialize the random seed
    int RandIndex = rand() % 3; //generates a random number between 0 and 4
    const char arrayNum[3] = {'r', 'p', 's'};
    return arrayNum[RandIndex];
}