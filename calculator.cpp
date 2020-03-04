
#include "selectionSort.hpp"
#include "ListContainer.hpp"
#include "vectorContainer.hpp"
#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "factory.hpp"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    Factory *myFactory = new Factory();
    Base *result = myFactory->parse(argv, argc);
    if (result == nullptr)
    {
        cout << "Invalid Input" << endl;
    }
    else
    {
        cout << result->evaluate() << endl;
        cout << result->stringify() << endl;
    }

    return 0;
}