#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <math.h>

class Pow : public Base
{
public:
    Pow(Base* Tx, Base* Ty) : Base()
    {
        x = Tx;
        y = Ty;
    }
    virtual double evaluate() { return pow(x->evaluate(),  y->evaluate()); }
    virtual std::string stringify() { return x->stringify() + " ** " + y->stringify(); }

private:
    Base* x;
    Base* y;
};

#endif //