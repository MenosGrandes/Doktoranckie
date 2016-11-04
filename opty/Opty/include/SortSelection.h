#ifndef SORTSELECTION_H
#define SORTSELECTION_H

#include "Sort.h"
class SortSelection : public Sort
{
    public:
         SortSelection(int n, int max);
         ~SortSelection();
        void _sort();
};

#endif // SORTSELECTION_H
