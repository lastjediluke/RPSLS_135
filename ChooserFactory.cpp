#include <iostream>
#include <string>
#include <stdio.h>   
#include "ChooserFactory.h" 

ChooserFactory::createChooser(string ChooserID)
{
	if (ChooserID == "ML") {
		return Chooser_ML();
	}
	else if (ChooserID == "Random") 
	{
		return Chooser_Rand();
	}
	else 
	{
		return void;
	}
}

#endif