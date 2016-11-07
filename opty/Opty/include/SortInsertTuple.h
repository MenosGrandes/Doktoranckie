#ifndef SORTINSERTTUPLE_H
#define SORTINSERTTUPLE_H

#include "../typdefs.hpp"
class SortInsertTuple
{
public:
     SortInsertTuple(){};
    ~SortInsertTuple(){};

    void sort(std::vector<int> &toSort)
    {
        const int sizeOfArray=toSort.size()-(toSort.size()&1);
//
        for(int i=0; i<sizeOfArray; i+=2)
        {
            if(toSort[i] > toSort[i+1])
            {
                const int tmp=toSort[i];
                toSort[i]=toSort[i+1];
                toSort[i+1]=tmp;
            }
        }

        for(int i=2; i<sizeOfArray; i+=2)
        {
            const int pom1 = toSort[i];
            const int pom2 = toSort[i+1];

            int j = i-1;

            while(j>=0 && toSort[j]>pom2)
            {
                toSort[j+2] = toSort[j+1] = toSort[j];
                j--;
            }
            toSort[j+2] = pom2;
            toSort[j+1] = pom1;

            while(j>=0 && toSort[j]>pom1)
            {
                toSort[j+1] = toSort[j];
                --j;
            }
            toSort[j+1] = pom1;
        }
        if(toSort.size()&1)
        {
            const int pom = toSort[toSort.size()-1];
            int k = toSort.size()-2;
            while(k>=0 && toSort[k]>pom)
            {
                toSort[k+1] = toSort[k];
                --k;
            }
            toSort[k+1] = pom;
        }

    }
};

#endif // SORTINSERTTUPLE_H
