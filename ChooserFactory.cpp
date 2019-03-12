  
#include "ChooserFactory.h" 

Chooser *ChooserFactory::make_chooser(std::string which)
{
	if (which == "smart") return new Chooser_ML();
	else return new Chooser_Rand();
}
