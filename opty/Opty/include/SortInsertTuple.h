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
        bool swapPair(int i);
        void swapPair(int i,bool&a1,bool&a2);



};

#endif // SORTINSERTTUPLE_H
