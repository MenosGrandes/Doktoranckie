#ifndef SORTINSERTTUPLE_H
#define SORTINSERTTUPLE_H

#include <Sort.h>
#include <utility>

class SortInsertTuple : public Sort
{
    public:
        SortInsertTuple(int n, int max);
        SortInsertTuple(int n, int* tab);

        virtual ~SortInsertTuple();
        void _sort();
    protected:

    private:

        void swap(int x,int y);
        void swapPair(int i);


};

#endif // SORTINSERTTUPLE_H
