#ifndef SORTINSERTTRIPLE_H
#define SORTINSERTTRIPLE_H

#include <Sort.h>


class SortInsertTriple : public Sort
{
    public:
         SortInsertTriple(int n, int max);
         ~SortInsertTriple();
        void __attribute__((hot)) _sort();
};

#endif // SORTINSERTTRIPLE_H
