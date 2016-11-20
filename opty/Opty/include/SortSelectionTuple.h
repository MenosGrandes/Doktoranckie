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
        int _begin = vectorSize;
        int _end = toSort.size()-1;
        while (vectorSize < _end)
        {
            int _min=_begin,_max=_end;
            for (int i = _begin; i < _end; ++i)
            {
                if (toSort[i] < toSort[_min])
                {
                    _min = i;
                }
                else if (toSort[i]> toSort[_max])
                {
                    _max = i;
                }
            }
            std::swap(toSort[_min],toSort[_begin]);
            if(_begin==_max)
            {
                _max=_min;
            }
            std::swap(toSort[_max],toSort[_end]);
            ++_begin;
            --_end;
        }
    }

};

#endif // SORTSELECTIONTUPLE_H
