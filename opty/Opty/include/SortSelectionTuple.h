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
