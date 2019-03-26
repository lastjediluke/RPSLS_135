#ifndef CHOOSER_H_
#define CHOOSER_H_

#include <iostream>
#include <string>
class Chooser
{
public:
    Chooser(){};
    virtual char make_choice(std::string s, int patternLen, char p) = 0;
    virtual ~Chooser() {}
};

#endif