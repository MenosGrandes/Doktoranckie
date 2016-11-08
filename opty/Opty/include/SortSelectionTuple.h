#ifndef SORTSELECTIONTUPLE_H
#define SORTSELECTIONTUPLE_H


#include "../typdefs.hpp"
#include <algorithm>
#include <iostream>
class SortSelectionTuple
{
public:
    SortSelectionTuple() {};
    ~SortSelectionTuple() {};
    void sort(std::vector<int> &toSort)
    {
        /**
        1)Jezeli najmniejszy znaleziony jest na ostatnim miejscu, a najwiekszy na pierwszym miejscu
        2)Jezeli najmniejszy znaleziony jest na ostatnim miejscu tablicy, tam gdzie powinnismy swap
        3)Jezeli najwiekszy znaleziony jest na pierwszym miejscu tablicy, tam gdzie powinnismy swap
        4)Jezeli nic z powyzszych.

        Najczesciej wywoluje sie:
        4
        3
        2
        1
        */
    }


    VintIter _begin = toSort.begin();
    VintIter _end = toSort.end() - 1;
    while (_begin < _end)
    {
        VintIter it=_begin,min=it,max=it;
        for (it = _begin; it <= _end; ++it)
        {
            if (*it < *min)
            {
                min = it;
            }
            else if (*it > *max)
            {
                max = it;
            }
        }
        std::iter_swap(min,_begin);
        if(_begin==max)
        {
            max=min;
        }
        std::iter_swap(max,_end);
        ++_begin;
        --_end;
    }
}

};

#endif // SORTSELECTIONTUPLE_H
