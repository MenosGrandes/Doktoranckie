#ifndef SORTSELECTIONTUPLE_H
#define SORTSELECTIONTUPLE_H

#include "Sort.h"

class SortSelectionTuple: public Sort
{
    public:
        SortSelectionTuple(int n, int* tab);
         SortSelectionTuple(int n, int max);
         ~SortSelectionTuple();
        void _sort();
};

#endif // SORTSELECTIONTUPLE_H
