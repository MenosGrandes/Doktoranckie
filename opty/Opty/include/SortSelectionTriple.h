#ifndef SORTSELECTIONTRIPLE_H
#define SORTSELECTIONTRIPLE_H

#include "../typdefs.hpp"
#include <assert.h>
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
        while (_begin < (_end-3))
        {
            VintIter it=_begin;
            VintIter _min1=it;
            VintIter _min2=it;
            VintIter _max=_end;

            if(*_begin<(*_begin+1))
            {
                _min2=(_begin+1);
                _min1=_begin;
            }
            else
            {
                _min2=_begin;
                _min1=(_begin+1);
            }


            for (it = (_begin+2); it < _end; ++it)
            {
                std::cout<<*it<<" ";
                if ((*it) <= (*_min1) && it!=_min2)
                {
                    _min2=_min1;
                    _min1 = it;
                }
                else if(*it < *_min2 &&  it!=_min1)
                {
                    _min2=it;
                }
                else if ((*it) > (*_max)&& (it!=_min2 && it!=_min1))
                {
                    _max = it;
                }
            }
            std::cout<<std::endl;
//            std::cout<<*(_min1)<<" "<<*(_min2)<<" "<<*(_max)<<std::endl;
//            std::cout<<"min1==min2 "<<CompareBool(_min1,_min2)<<std::endl;;
//            std::cout<<"_min2==_max "<<CompareBool(_min2,_max)<<std::endl;;
//            std::cout<<"_max==_min1 "<<CompareBool(_max,_min1)<<std::endl;;
            assert(_min1!=_min2);
            assert(_min2!=_max);
            assert(_max!=_min1);




            _begin+=2;
            --_end;
        }
    }

};

#endif // SORTSELECTIONTRIPLE_H
