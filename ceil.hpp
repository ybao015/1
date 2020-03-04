#ifndef __CEIL_HPP__
#define __CEIL_HPP__

#include "decorator.hpp"
#include <math.h>

using namespace std;

class Ceil : public Decorator
{
public:
    Ceil(Base *Tx) : Decorator(Tx){}

    virtual double evaluate()
    {
        return ceil(x->evaluate());
    };

    virtual string stringify(){};

};

#endif