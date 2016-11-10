#ifndef SORTSELECTIONTRIPLE_H
#define SORTSELECTIONTRIPLE_H

#include "../typdefs.hpp"
class SortSelectionTriple
{
public:
    SortSelectionTriple() {};
    ~SortSelectionTriple() {};
    void sort(std::vector<int>&toSort)
    {
        int vectorSize=0;

//        if(toSort.size()%2!=0)
//        {
//            vectorSize++;
//            std::iter_swap((std::min_element(toSort.begin(),toSort.end())),toSort.begin());
//        }

        VintIter _begin = toSort.begin()+vectorSize;
        VintIter _end = toSort.end() - 1;
        while (_begin < _end)
        {
            VintIter it=_begin;
            VintIter _min1=it;
            VintIter _min2=it;
            VintIter _max=it;
            for (it = _begin; it <= _end; ++it)
            {
                if ((*it) < (*_min1))
                {
                    _min2=_min1;
                    _min1 = it;
                }
                else if((*it)<(*_min2)&&_min2!=_min1)
                {
                    _min2=it;
                }
                else if ((*it) > (*_max))
                {
                    _max = it;
                }
            }

            std::cout<<*(_min1)<<" "<<*(_min2)<<" "<<*(_max)<<std::endl;

            std::iter_swap(_min1,_begin);
            std::iter_swap(_min2,_begin+1);
            std::iter_swap(_max,_end);

//            if(_begin==_max)
//            {
//                _max=_min;
//            }
//            std::iter_swap(_max,_end);
            _begin+=2;
            --_end;
        }
    }

};

#endif // SORTSELECTIONTRIPLE_H
