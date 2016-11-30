#ifndef SORTSELECTIONTRIPLE_H
#define SORTSELECTIONTRIPLE_H

#include "SortBehaviour.h"
class SortSelectionTriple : public SortBehaviour
{
public:
    static const SortType m_sortType=TRIPLE_SELECTION;

    SortSelectionTriple() {};
    ~SortSelectionTriple() {};
    void sort(std::vector<int>&toSort)
    {
        for (int k = 0; k < toSort.size(); k += 3)
        {
                //Sort first 3 indexes
                int indexOfMax_Min = 0;
                int indexOfMax_Mid = 1;
                int indexOfMax_Max = 2;
                if (toSort[0] > toSort[1])
                {
                        indexOfMax_Min = 1;
                        indexOfMax_Mid = 0;
                }
                if (toSort[2] <= toSort[indexOfMax_Min])
                {
                        indexOfMax_Max = indexOfMax_Mid;
                        indexOfMax_Mid = indexOfMax_Min;
                        indexOfMax_Min = 2;
                }
                else if (toSort[2] <= toSort[indexOfMax_Mid])
                {
                        indexOfMax_Max = indexOfMax_Mid;
                        indexOfMax_Mid = 2;
                }
int i=0;
                for ( i = 3; i < toSort.size() - k; i++)
                {
                        if (toSort[i] > toSort[indexOfMax_Min])
                        {
                                if (toSort[i] >= toSort[indexOfMax_Max])
                                {
                                        indexOfMax_Min = indexOfMax_Mid;
                                        indexOfMax_Mid = indexOfMax_Max;
                                        indexOfMax_Max = i;
                                }
                                else if (toSort[i] >= toSort[indexOfMax_Mid])
                                {
                                        indexOfMax_Min = indexOfMax_Mid;
                                        indexOfMax_Mid = i;
                                }
                                else
                                {
                                        indexOfMax_Min = i;
                                }
                        }
                }


                int tmp3 = toSort[indexOfMax_Max];
                toSort[indexOfMax_Max] = toSort[i - 1];
                toSort[i - 1] = tmp3;
                if (i - 1 == indexOfMax_Mid)
                {
                        indexOfMax_Mid = indexOfMax_Max;
                }
                else if (i - 1 == indexOfMax_Min)
                {
                        indexOfMax_Min = indexOfMax_Max;
                }


                int tmp2 = toSort[indexOfMax_Mid];
                toSort[indexOfMax_Mid] = toSort[i - 2];
                toSort[i - 2] = tmp2;
                if (i - 2 == indexOfMax_Min)
                {
                        indexOfMax_Min = indexOfMax_Mid;
                }

                int tmp1 = toSort[indexOfMax_Min];
                toSort[indexOfMax_Min] = toSort[i - 3];
                toSort[i - 3] = tmp1;
        }

    }

};
/*
#ifndef SORTSELECTIONTRIPLE_H
#define SORTSELECTIONTRIPLE_H

#include "../typdefs.hpp"
#include <assert.h>
class SortSelectionTriple
{
public:
    SortSelectionTriple() {};
    ~SortSelectionTriple() {};
   void sort(std::vector<int> &toSort)
    {

        int vectorSize=0;

        if(toSort.size()%2!=0)
        {
            vectorSize++;
            std::iter_swap((std::min_element(toSort.begin(),toSort.end())),toSort.begin());
        }
        int vectorSize = vectorSize;
        int _end = toSort.size()-1;
        while (vectorSize < _end)
        {
            int _min=vectorSize,_max=_end;
            for (int i = vectorSize; i < _end; ++i)
            {
                if (toSort[i] < toSort[_min])
                {
                    _min = i;
                }
                else if (toSort[i]> toSort[_max])z
                {
                    _max = i;
                }
            }
            std::swap(toSort[_min],toSort[vectorSize]);
            if(vectorSize==_max)
            {
                _max=_min;
            }
            std::swap(toSort[_max],toSort[_end]);
            ++vectorSize;
            --_end;
        }
    }
};

#endif // SORTSELECTIONTRIPLE_H




*/



#endif // SORTSELECTIONTRIPLE_H
