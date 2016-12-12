#ifndef BITONICSORT_H
#define BITONICSORT_H

#include<bits/stdc++.h>

#include "SortBehaviour.h"

/*
http://www.iti.fh-flensburg.de/lang/algorithmen/sortieren/bitonic/oddn.htm
*/

class BitonicSort : public SortBehaviour
{
public :
    static const SortType m_sortType=BITONIC;



    int sort(std::vector<int>& toSort)
    {
        compareCounter=0;
        this->a= toSort;
        bitonicSort(0, toSort.size(), ASCENDING);
        toSort = this->a;
        return compareCounter;
    }
private :
    void bitonicSort(int lo, int n, bool dir)
    {
        compareCounter++;
        if (n>1)
        {
            int m=n/2;
            bitonicSort(lo, m, !dir);
            bitonicSort(lo+m, n-m, dir);
            bitonicMerge(lo, n, dir);
        }
    }

    void bitonicMerge(int lo, int n, bool dir)
    {
        compareCounter++;
        if (n>1)
        {
            const int m=greatestPowerOfTwoLessThan(n);
            for (int i=lo; i<lo+n-m; i++)
            {
                compareCounter++;
                if (dir==(a[i]>a[i+m]))
                {
                   const int t=a[i];
                    a[i]=a[i+m];
                    a[i+m]=t;
                }
            }
            bitonicMerge(lo, m, dir);
            bitonicMerge(lo+m, n-m, dir);
        }
    }



    int greatestPowerOfTwoLessThan(int n)
    {
        int k=1;
        while (k<n)
            {
                compareCounter++;
                k=k<<1;
            }
        return k>>1;
    }
    std::vector<int>a;
    bool ASCENDING=true;    // sorting direction
};

#endif // BITONICSORT_H
