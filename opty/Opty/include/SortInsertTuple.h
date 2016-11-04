#ifndef SORTINSERTTUPLE_H
#define SORTINSERTTUPLE_H

#include <Sort.h>
#include <utility>

class SortInsertTuple : public Sort
{
public:
    SortInsertTuple(int n, int max);
    ~SortInsertTuple();
    void _sort() __attribute__ ((pure));;
};

#endif // SORTINSERTTUPLE_H
