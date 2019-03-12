#ifndef CHOOSER_ML_H_
#define CHOOSER_ML_H_

#include "Chooser.h"
#include <iostream>
#include <string>
#include <stdio.h>

class Chooser_ML: public Chooser
{
public: 
	Chooser_ML(){};
	void make_choice(std::string which);
};

#endif