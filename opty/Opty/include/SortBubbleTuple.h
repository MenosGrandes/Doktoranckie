#ifndef SORTBUBBLETUPLE_H
#define SORTBUBBLETUPLE_H

#include <Sort.h>


class SortBubbleTuple : public Sort
{
    public:
            SortBubbleTuple(int n, int max);
            SortBubbleTuple(int n, int*tab);
        ~SortBubbleTuple();
    void _sort();
    protected:

    private:
};

#endif // SORTBUBBLETUPLE_H
