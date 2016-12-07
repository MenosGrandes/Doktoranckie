#ifndef SORTINSERTTRIPLE_H
#define SORTINSERTTRIPLE_H

#include "SortBehaviour.h"
class SortInsertTriple: public SortBehaviour
{
public:
    static const SortType m_sortType=TRIPLE_INSERT;

    SortInsertTriple() {};
    ~SortInsertTriple() {};
    int sort(std::vector<int>&toSort)
    {
        const int arrayDivider = (toSort.size()%3);
        int comprasions=1;
        if(toSort.size()%3!=0)
        {
            for(int i=1; i<arrayDivider; i++)
            {
                comprasions++;
                const int pom = toSort[i];
                int j = i-1;
                while(j>=0 && toSort[j]>pom)
                {
                    comprasions++;
                    toSort[j+1] = toSort[j];
                    --j;
                }
                toSort[j+1] = pom;
            }

        }
        for(unsigned int i=arrayDivider; i<toSort.size(); i+=3)
        {
            comprasions++;
            if(toSort[i] < toSort[i+1])
            {
                if(toSort[i+2]<toSort[i])
                {
                    comprasions++;
                    std::swap(toSort[i],toSort[i+2]);
                }
            }
            else
            {
                comprasions++;
                if(toSort[i+1]<toSort[i+2])
                {
                    std::swap(toSort[i],toSort[i+1]);
                }
                else
                {
                    std::swap(toSort[i],toSort[i+2]);
                }
            }
            comprasions++;
            if(toSort[i+2]<toSort[i+1])
            {
                std::swap(toSort[i+1],toSort[i+2]);
            }

            const int pom1 = toSort[i];
            const int pom2 = toSort[i+1];
            const int pom3 = toSort[i+2];

            int j = i-1;
            comprasions+=2;
            while(j>=0 && toSort[j]>pom3)
            {
                comprasions+=2;
                toSort[j+3] =  toSort[j];
                j--;

            }
            toSort[j+3] = pom3;
            toSort[j+2] = pom2;
            toSort[j+1] = pom1;
            comprasions+=2;
            while(j>=0 && toSort[j]>pom2)
            {
                comprasions+=2;
                toSort[j+2] =  toSort[j];
                j--;
            }
            toSort[j+2] = pom2;
            toSort[j+1] = pom1;
            comprasions+=2;
            while(j>=0 && toSort[j]>pom1)
            {
                comprasions+=2;
                toSort[j+1] = toSort[j];
                --j;
            }
            toSort[j+1] = pom1;
        }
        return comprasions;
    };
};
#endif // SORTINSERTTRIPLE_H
