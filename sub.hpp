#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base
{
public:
    Sub(Base* Tx, Base* Ty) : Base()
    {
        x = Tx;
        y = Ty;
    }
    virtual double evaluate() { return x->evaluate() - y->evaluate() ; }
    virtual std::string stringify() { return x->stringify() + " - " + y->stringify(); }

private:
    Base* x;
    Base* y;
};

#endif //