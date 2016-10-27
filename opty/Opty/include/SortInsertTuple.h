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
protected:

private:

    bool swapPair(int i);
    void swapPair(int i,bool&a1,bool&a2);
    void _swap(int x,int y,int z,int w);
    void _swap3(int x,int y, int z);



};

#endif // SORTINSERTTUPLE_H
