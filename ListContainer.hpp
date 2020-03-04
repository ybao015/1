#ifndef __LISTCONTAINER_HPP_
#define __LISTCONTAINER_HPP_
#include "container.hpp"
#include <list>
#include <iostream>
#include "sort.hpp"
#include "base.hpp"

using namespace std;

class Sort;
class Base;

class ListContainer : public Container
{
public:
	ListContainer() : Container(){};
	ListContainer(Sort *function) : Container(function){};

	void set_sort_function(Sort *sort_function)
	{
		this->sort_function = sort_function;
	}

	virtual void add_element(Base *element)
	{
		elementsContainer.push_back(element);
	}

	virtual void print()
	{
		for (auto const &i : elementsContainer)
		{
			cout << i->stringify() << endl;
		}
	}

	virtual void swap(int i, int j)
	{
		list<Base *>::iterator k = elementsContainer.begin();
		list<Base *>::iterator m = elementsContainer.begin();
		advance(k,i);
		advance(m,j);
		Base *temp = *k;
		*k = *m;
		*m = temp;
	}

	virtual void sort()
	{
		sort_function->sort(this);
	}

	virtual Base *at(int i)
	{
		list<Base *>::iterator it = elementsContainer.begin();
		advance(it, i);
		return *it;
	}

	virtual int size()
	{
		return elementsContainer.size();
	}

protected:
	list<Base *> elementsContainer;
};

#endif
