#ifndef SORTSELECTIONTRIPLE_H
#define SORTSELECTIONTRIPLE_H

#include "../typdefs.hpp"
#include <limits>
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

        int _begin = vectorSize;
        int _end = toSort.size();
         int end = (int)(toSort.size()/3);
        while (end>0)
        {


            int _min1 = std::numeric_limits<int>::max();
            int _min2 = std::numeric_limits<int>::max();
            int _max =  std::numeric_limits<int>::min();


            for (int i = _begin; i < _end; ++i)
            {
                std::cout<<toSort[i]<<" ";
                if (toSort[i] < _min1)
                {
                    _min2=_min1;
                    _min1 = toSort[i];
                }
                else if(toSort[i]<_min2)
                {
                    _min2=toSort[i];
                }

                if (toSort[i] > _max)
                {
                    _max = toSort[i];
                }
            }
            std::cout<<std::endl<<"min1:"<<_min1<<" min2:"<<_min2<<" max:"<<_max<<std::endl;
            _begin+=2;
            --_end;
            --end;
        }
    }
};

#endif // SORTSELECTIONTRIPLE_H
