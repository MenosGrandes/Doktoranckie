#ifndef SORTINSERTTUPLE_H
#define SORTINSERTTUPLE_H

#include <Sort.h>
#include <utility>

class SortInsertTuple : public Sort
{
public:
    SortInsertTuple(int n, int max);
    SortInsertTuple(int n, int* tab);

    ~SortInsertTuple();
    void _sort();




};

#endif // SORTINSERTTUPLE_H
