#ifndef CHOOSER_ML_H_
#define CHOOSER_ML_H_

#include "Chooser.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

class Chooser_ML: public Chooser
{
public: 
	Chooser_ML(){ std::cout << "Smart Chooser Created" << std::endl; }
	~Chooser_ML(){ std::cout << "Smart Chooser Killed" << std::endl; }
	char make_choice(std::string s, int patternLen, char p);
private:
	
};

#endif