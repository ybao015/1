#ifndef __BUBBLESORT_HPP__
#define __BUBBLESORT_HPP__

#include "container.hpp"
#include "sort.hpp"

using namespace std;

class BubbleSort : public Sort
{
public:
	virtual void sort(Container *container)
	{
		int i, j;
		int size = container->size();
		for (i = 0; i < size - 1; i++)
		{
			// Last i elements are already in place
			for (j = 0; j < size - i - 1; j++)
			{
				if (container->at(j)->evaluate() > container->at(j + 1)->evaluate())
				{
					container->swap(j, j + 1);
				}
			}
		}
	}
};

#endif
