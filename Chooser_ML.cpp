   #include "Chooser_ML.h"
   #include <fstream>
   #include <time.h>

char Chooser_ML::make_choice(std::string s, int patternLen, char p)
{
	// set random hand
   srand ( time(NULL) );         // initialize the random seed
   int RandIndex = rand() % 3;   // generates a random number between 0 and 2
   const char arrayNum[3] = {'r', 'p', 's'};
   std::cout << "Choice is " << p << std::endl;
   if (s.length() == patternLen)
   {
      // no pattern match
      if (p == 'x') 
      { 
         return arrayNum[RandIndex]; 
      }
      else
      {
         return p;
      }
   }
   
   // else we will pick a random one
   else
   {
      return arrayNum[RandIndex]; 
   }
}