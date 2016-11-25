#ifndef BITONICSORT_H
#define BITONICSORT_H

#include "../typdefs.hpp"

class BitonicSort
{
public:
    BitonicSort() {}

    void sort(std::vector<int>&toSort)
    {
        this->a = toSort;
        bitonicSort(0, a.size(), true);

        toSort = this->a;
       for(int i : a)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
private:

    void bitonicSort(int lo, int n, bool dir)
    {
        if (n>1)
        {
            int m=n/2;
            bitonicSort(lo, m, true);
            bitonicSort(lo+m, m, false);
            bitonicMerge(lo, n, dir);
        }
    }

    void bitonicMerge(int lo, int n, bool dir)
    {
        if (n>1)
        {
            int m=n/2;
            for (int i=lo; i<lo+m; i++)
                compare(i, i+m, dir);
            bitonicMerge(lo, m, dir);
            bitonicMerge(lo+m, m, dir);
        }
    }

    void compare(int i, int j, bool dir)
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
    std::vector<int> a;

};

#endif // BITONICSORT_H
