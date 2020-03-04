#ifndef __VECTORCONTAINER_HPP__
#define __VECTORCONTAINER_HPP__

#include "container.hpp"
#include <vector>
#include "sort.hpp"
#include "base.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

class Sort;
class Base;
class Container;

class VectorContainer : public Container
{

protected:
    Sort *sort_function; 
    vector<Base *> myContainer;

public:
    VectorContainer() : Container(){};
    VectorContainer(Sort *function) : Container(function){};

    void set_sort_function(Sort *sort_function)
    {
        this->sort_function = sort_function;
    }

    virtual void add_element(Base *element)
    {
        myContainer.push_back(element);
    }

    virtual void print()
    {
        int size = myContainer.size();
        for (int i = 0; i < size; i++)
        {
            cout << myContainer[i]->stringify() << endl;
        }
    }

    virtual void sort()
    {
        sort_function->sort(this);
    }

    virtual void swap(int i, int j)
    {
        Base *temp = myContainer.at(i);
        myContainer.at(i) = myContainer.at(j);
        myContainer.at(j) = temp;
    }

    virtual Base *at(int i)
    {
        return myContainer[i];
    }

    virtual int size()
    {
        return myContainer.size();
    }
};

#endif //