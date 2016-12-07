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

      std::vector<int>a;
     bool ASCENDING=true;    // sorting direction

   int sort(std::vector<int>& toSort)
    {
        this->a= toSort;
        bitonicSort(0, toSort.size(), ASCENDING);
        toSort = this->a;
        return 0;
    }

     void bitonicSort(int lo, int n, boolean dir)
    {
        if (n>1)
        {
            int m=n/2;
            bitonicSort(lo, m, !dir);
            bitonicSort(lo+m, n-m, dir);
            bitonicMerge(lo, n, dir);
        }
    }

     void bitonicMerge(int lo, int n, boolean dir)
    {
        if (n>1)
        {
            int m=greatestPowerOfTwoLessThan(n);
            for (int i=lo; i<lo+n-m; i++)
                compare(i, i+m, dir);
            bitonicMerge(lo, m, dir);
            bitonicMerge(lo+m, n-m, dir);
        }
    }

     void compare(int i, int j, boolean dir)
    {
        if (dir==(a[i]>a[j]))
            exchange(i, j);
    }

     void exchange(int i, int j)
    {
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
    }

     int greatestPowerOfTwoLessThan(int n)
    {
        int k=1;
        while (k<n)
            k=k<<1;
        return k>>1;
    }

};

#endif // BITONICSORT_H
