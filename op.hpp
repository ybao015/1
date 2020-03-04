#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base
{
public:
    Op(double value) : Base() { myValue = value; }
    virtual double evaluate() { return myValue; }
    virtual std::string stringify() { return std::to_string(myValue); }
 
private:
    double myValue;
};

#endif //__OP_HPP__
