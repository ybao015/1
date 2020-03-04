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
    char *lol1 = '3';
    char *lol2 = '+';
    char *lol3 = '2';
    char **haha = {'d', lol1, lol2, lol3, NULL};
    int idk = 3;
    Factory *myFactory = new Factory();
    Base *result = myFactory->parse(haha, idk);
    cout << result->evaluate() << endl;
    cout << result->stringify() << endl;
    return 0;
}
