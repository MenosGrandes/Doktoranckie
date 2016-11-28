#ifndef BITONICSORT_H
#define BITONICSORT_H

#include<bits/stdc++.h>

#include "SortBehaviour.h"
class BitonicSort : public SortBehaviour
{
public:
    static const SortType m_sortType=BITONIC;

    BitonicSort() {}
    ~BitonicSort() {}
    void sort(std::vector<int>& toSort)
    {
        BOOST_ASSERT_MSG(toSort.size() && !(toSort.size() & (toSort.size() - 1)),"BitonicSearch need vector to have 2^x size!") ;
        bitonicSort(&toSort[0],0, toSort.size()+1, 1);


    }
private:

    /*The parameter dir indicates the sorting direction, ASCENDING
       or DESCENDING; if (a[i] > a[j]) agrees with the direction,
       then a[i] and a[j] are interchanged.*/
    void compAndSwap(int a[], int i, int j, int dir)
    {
        if (dir==(a[i]>a[j]))
            std::swap(a[i],a[j]);
    }

    /*It recursively sorts a bitonic sequence in ascending order,
      if dir = 1, and in descending order otherwise (means dir=0).
      The sequence to be sorted starts at index position low,
      the parameter cnt is the number of elements to be sorted.*/
    void bitonicMerge(int a[], int low, int cnt, int dir)
    {
        if (cnt>1)
        {
            int k = cnt/2;
            for (int i=low; i<low+k; i++)
                compAndSwap(a, i, i+k, dir);
            bitonicMerge(a, low, k, dir);
            bitonicMerge(a, low+k, k, dir);
        }
    }

    /* This function first produces a bitonic sequence by recursively
        sorting its two halves in opposite sorting orders, and then
        calls bitonicMerge to make them in the same order */
    void bitonicSort(int a[],int low, int cnt, int dir)
    {
        if (cnt>1)
        {
            int k = cnt/2;

            // sort in ascending order since dir here is 1
            bitonicSort(a, low, k, 1);

            // sort in descending order since dir here is 0
            bitonicSort(a, low+k, k, 0);

            // Will merge wole sequence in ascending order
            // since dir=1.
            bitonicMerge(a,low, cnt, dir);
        }
    }


};

#endif // BITONICSORT_H
