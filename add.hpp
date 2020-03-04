#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add : public Base
{
public:
    Add(Base* Tx, Base* Ty) : Base()
    {
        x = Tx;
        y = Ty;
    }
    virtual double evaluate() { return x->evaluate() + y->evaluate() ; }
    virtual std::string stringify() { return x->stringify() + " + " + y->stringify(); }

private:
    Base* x;
    Base* y;
};

#endif //