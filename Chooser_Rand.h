#ifndef CHOOSER_RAND_H_
#define CHOOSER_RAND_H_

#include "Chooser.h"
#include <iostream>
#include <string>
#include <stdio.h>

class Chooser_Rand : public Chooser
{
public:
	Chooser_Rand(){};
	void make_choice(std::string which);
};

#endif