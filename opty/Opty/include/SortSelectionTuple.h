#ifndef SORTSELECTIONTUPLE_H
#define SORTSELECTIONTUPLE_H
#include <algorithm>
#include <iostream>
#include "SortBehaviour.h"
class SortSelectionTuple : public SortBehaviour
{
public:
    static const SortType m_sortType=TUPLE_SELECTION;
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
    int sort(std::vector<int> &toSort)
    {
        int comprasions=0;

        int vectorSize=0;
        comprasions+=2;
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
                comprasions++;
                if ((*it) < (*_min))
                {
                    _min = it;
                }
                else if ((*it) > (*_max))
                {
                    comprasions++;
                    _max = it;
                }
            }
            std::iter_swap(_min,_begin);
            comprasions+=2;
            if(_begin==_max)
            {
                _max=_min;
            }
            std::iter_swap(_max,_end);
            ++_begin;
            --_end;
        }
        return comprasions;
    }







};

/*
Robimy z wszystkiego pary.
Sortujemy wszystkie w kolejnosci rosnacej,
z pierwszych liczb kazdej pary wybieramy najmniejsza a z drugich najwieksza.
zamieniamy miejscami najmniejsza z poczatkiem a najwieksza z koncem





[3 45] [67 91] [13 82]
 |______|_______|
     3      13
     |______|
        3

[3 45] [67 91] [13 82]
    |______|_______|
        91      91
        |______|
           91


[3 45] [67 82] [13 91] -> 3 [45 67] [82 13] 91 -> 3 [45 67] [13 82] 91

[45 67] [13 82]
 |_______|
     13


[45 67] [13 82]
    |_______|
     82


3 [13 67] [45 82] 91
3 13 [67 45] 82 91 -> 3 13 45 69 82 91


    void sort(std::vector<int> &toSort)
    {

    int _begin=0;
    int _end = toSort.size()-1;
    while(_begin<_end)
        {

        for(int i=_begin;i<=_end;i+=2)
        {
           if(toSort[i]>toSort[i+1])
           {
               std::swap(toSort[i],toSort[i+1]);
           }
        }
        int _min=_begin;
        int _max=_begin;

        for(int i=_begin;i<_end;i++)
        {
            if(toSort[_min]>=toSort[i])
            {
                _min=i;
            }else if(toSort[_min]<=toSort[i])
            {
                _max=i;
            }
        }
        std::swap(toSort[_begin],toSort[_min]);
        std::swap(toSort[_end],toSort[_max]);

        _begin++;
        _end--;
    }
    }
};

*/
#endif // SORTSELECTIONTUPLE_H
