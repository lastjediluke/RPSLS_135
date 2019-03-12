#ifndef CHOOSER_H_
#define CHOOSER_H_

#include <iostream>
#include <string>
class Chooser
{
public:
    Chooser(){};
    virtual void make_choice(std::string which) = 0;
};

#endif