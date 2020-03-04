#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base
{
public:
    Div(Base* Tx, Base* Ty) : Base()
    {
        x = Tx;
        y = Ty;
    }
    virtual double evaluate() { return x->evaluate() / y->evaluate() ; }
    virtual std::string stringify() { return x->stringify() + " / " + y->stringify(); }

private:
    Base* x;
    Base* y;
};

#endif