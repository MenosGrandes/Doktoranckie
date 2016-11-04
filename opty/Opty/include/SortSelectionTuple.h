#ifndef SORTSELECTIONTUPLE_H
#define SORTSELECTIONTUPLE_H

#include "Sort.h"
#include <algorithm>
class SortSelectionTuple: public Sort
{
    public:
         SortSelectionTuple(int n, int max);
         ~SortSelectionTuple();
        void inline _sort();
};

#endif // SORTSELECTIONTUPLE_H
