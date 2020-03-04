#ifndef __FACTORY__HPP__
#define __FACTORY__HPP__

#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "op.hpp"
#include "container.hpp"
#include "vectorContainer.hpp"
#include "ListContainer.hpp"
#include <queue>
#include <string.h>
#include <iostream>

using namespace std;

class Factory
{
public:
    Factory(){};
    Base *parse(char **input, int length)
    {
        queue<char *> myNumber;
        queue<char *> myOp;
        for (int i = 1; i < length; i++)
        {
            if (strcmp(input[i], "+") == 0 || strcmp(input[i], "-") == 0 || strcmp(input[i], "*") == 0 || strcmp(input[i], "/") == 0)
            {
                myOp.push(input[i]);
            }
            else if(isdigit(*input[i]))
            {
                myNumber.push(input[i]);
            }
            else
            {
                return nullptr;
            }
            
        }

        queue<Base *> myBaseQueue;
        queue<Base *> myNumberQueue;
        while (!myNumber.empty())
        {
            Op *value = new Op(stoi(myNumber.front()));
            myNumberQueue.push(value);
            myNumber.pop();
        }

        while (!myNumberQueue.empty())
        {
            if (myBaseQueue.empty())
            {
                if (strcmp(myOp.front(), "+") == 0)
                {
                    Base *value1 = myNumberQueue.front();
                    myNumberQueue.pop();
                    Base *value2 = myNumberQueue.front();
                    myNumberQueue.pop();
                    Add *myAdd = new Add(value1, value2);
                    myOp.pop();
                    myBaseQueue.push(myAdd);
                }
                else if (strcmp(myOp.front(), "-") == 0)
                {
                    Base *value1 = myNumberQueue.front();
                    myNumberQueue.pop();
                    Base *value2 = myNumberQueue.front();
                    myNumberQueue.pop();
                    Sub *mySub = new Sub(value1, value2);
                    myOp.pop();
                    myBaseQueue.push(mySub);
                }
                else if (strcmp(myOp.front(), "*") == 0)
                {
                    Base *value1 = myNumberQueue.front();
                    myNumberQueue.pop();
                    Base *value2 = myNumberQueue.front();
                    myNumberQueue.pop();
                    Mult *myMult = new Mult(value1, value2);
                    myOp.pop();
                    myBaseQueue.push(myMult);
                }
                else if (strcmp(myOp.front(), "/") == 0)
                {
                    Base *value1 = myNumberQueue.front();
                    myNumberQueue.pop();
                    Base *value2 = myNumberQueue.front();
                    myNumberQueue.pop();
                    Div *myDiv = new Div(value1, value2);
                    myOp.pop();
                    myBaseQueue.push(myDiv);
                }
            }
            else
            {
                if (strcmp(myOp.front(), "+") == 0)
                {
                    Base *value1 = myBaseQueue.front();
                    myBaseQueue.pop();
                    Base *value2 = myNumberQueue.front();
                    myNumberQueue.pop();
                    Add *myAdd = new Add(value1, value2);
                    myOp.pop();
                    myBaseQueue.push(myAdd);
                }
                else if (strcmp(myOp.front(), "-") == 0)
                {
                    Base *value1 = myBaseQueue.front();
                    myBaseQueue.pop();
                    Base *value2 = myNumberQueue.front();
                    myNumberQueue.pop();
                    Sub *mySub = new Sub(value1, value2);
                    myOp.pop();
                    myBaseQueue.push(mySub);
                }
                else if (strcmp(myOp.front(), "*") == 0)
                {
                    Base *value1 = myBaseQueue.front();
                    myBaseQueue.pop();
                    Base *value2 = myNumberQueue.front();
                    myNumberQueue.pop();
                    Mult *myMult = new Mult(value1, value2);
                    myOp.pop();
                    myBaseQueue.push(myMult);
                }
                else if (strcmp(myOp.front(), "/") == 0)
                {
                    Base *value1 = myBaseQueue.front();
                    myBaseQueue.pop();
                    Base *value2 = myNumberQueue.front();
                    myNumberQueue.pop();
                    Div *myDiv = new Div(value1, value2);
                    myOp.pop();
s                    myBaseQueue.push(myDiv);
                }
            }
        }

        return myBaseQueue.front();
        // char *str = strdup(*input);
        // queue<char *> myOp;
        // char *token = strtok(str, " ");
        // while (token != NULL)
        // {
        //     myOp.push(token);
        //     token = strtok(NULL, "");
        // }
    }
};

#endif