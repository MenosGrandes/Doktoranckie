#ifndef SORTSELECTION_H
#define SORTSELECTION_H

#include "Sort.h"
#include "../typdefs.hpp"
class SortSelection : public Sort
{
    public:
         SortSelection(int n, int max);
         ~SortSelection();
        void _sort();
};

#endif // SORTSELECTION_H
