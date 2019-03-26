#ifndef CHOOSERFACTORY_H_
#define CHOOSERFACTORY_H_

#include "Chooser.h"
#include <iostream>
#include <string>
#include <stdio.h> 
#include "Chooser_Rand.h"
#include "Chooser_ML.h"

class ChooserFactory
{
public:
    static Chooser *make_chooser(std::string which);
};

#endif
