#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base
{
public:
    Mult(Base* Tx, Base* Ty) : Base()
    {
        x = Tx;
        y = Ty;
    }
    virtual double evaluate() { return x->evaluate() * y->evaluate() ; }
    virtual std::string stringify() { return x->stringify() + " * " + y->stringify(); }

private:
    Base* x;
    Base* y;
};

#endif //