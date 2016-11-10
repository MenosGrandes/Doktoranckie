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
    void sort(std::vector<int> &toSort)
    {

        int vectorSize=0;

        if(toSort.size()%2!=0)
        {
            vectorSize++;
            std::iter_swap((std::min_element(toSort.begin(),toSort.end())),toSort.begin());
        }

        VintIter _begin = toSort.begin()+vectorSize;
        VintIter _end = toSort.end() - 1;
        while (_begin < _end)
        {
            VintIter it=_begin,_min=it,_max=it;
            for (it = _begin; it <= _end; ++it)
            {
                if ((*it) < (*_min))
                {
                    _min = it;
                }
                else if ((*it) > (*_max))
                {
                    _max = it;
                }
            }
            std::iter_swap(_min,_begin);
            if(_begin==_max)
            {
                _max=_min;
            }
            std::iter_swap(_max,_end);
            ++_begin;
            --_end;
        }
}

};

#endif // SORTSELECTIONTUPLE_H
