#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "Sort.h"

class BubbleSort : public Sort
{
public:
    BubbleSort(int n, int max);
    BubbleSort(int n, int*tab);
    ~BubbleSort();
    void _sort();
protected:

private:
};

#endif // BUBBLESORT_H
