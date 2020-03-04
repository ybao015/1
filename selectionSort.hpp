#ifndef __SELECTIONSORT_HPP__
#define __SELECTIONSORT_HPP__

#include "container.hpp"
#include "sort.hpp"

using namespace std;

class Sort;
class SelectionSort : public Sort
{
public:
    virtual void sort(Container *container)
    {
        int i, j, min_idx;
        // One by one move boundary of unsorted subarray
        for (i = 0; i < container->size() - 1; i++)
        {
            // Find the minimum element in unsorted array
            min_idx = i;
            for (j = i + 1; j < container->size(); j++)
                if (container->at(j)->evaluate() < container->at(min_idx)->evaluate())
                    min_idx = j;

            // Swap the found minimum element with the first element
            container->swap(min_idx, i);
        }
    }
};

#endif //__SORT_HPP__
