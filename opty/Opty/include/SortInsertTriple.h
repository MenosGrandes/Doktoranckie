#ifndef SORTINSERTTRIPLE_H
#define SORTINSERTTRIPLE_H

#include "SortBehaviour.h"
class SortInsertTriple: public SortBehaviour
{
public:
    static const SortType m_sortType=TRIPLE_INSERT;

    SortInsertTriple() {};
    ~SortInsertTriple() {};
    uint256_t sort(std::vector<int>&toSort)
    {
        const int arrayDivider = (toSort.size()%3);
        compareCounter=1;
        if(toSort.size()%3!=0)
        {
            for(int i=1; i<arrayDivider; i++)
            {
                compareCounter++;
                const int pom = toSort[i];
                int j = i-1;
                while(j>=0 && toSort[j]>pom)
                {
                    compareCounter++;
                    toSort[j+1] = toSort[j];
                    --j;
                }
                toSort[j+1] = pom;
            }

        }
        for(unsigned int i=arrayDivider; i<toSort.size(); i+=3)
        {
            compareCounter++;
            if(toSort[i] < toSort[i+1])
            {
                if(toSort[i+2]<toSort[i])
                {
                    compareCounter++;
                    std::swap(toSort[i],toSort[i+2]);
                }
            }
            else
            {
                compareCounter++;
                if(toSort[i+1]<toSort[i+2])
                {
                    std::swap(toSort[i],toSort[i+1]);
                }
                else
                {
                    std::swap(toSort[i],toSort[i+2]);
                }
            }
            compareCounter++;
            if(toSort[i+2]<toSort[i+1])
            {
                std::swap(toSort[i+1],toSort[i+2]);
            }

            const int pom1 = toSort[i];
            const int pom2 = toSort[i+1];
            const int pom3 = toSort[i+2];

            int j = i-1;
            compareCounter+=2;
            while(j>=0 && toSort[j]>pom3)
            {
                compareCounter+=2;
                toSort[j+3] =  toSort[j];
                j--;

            }
            toSort[j+3] = pom3;
            toSort[j+2] = pom2;
            toSort[j+1] = pom1;
            compareCounter+=2;
            while(j>=0 && toSort[j]>pom2)
            {
                compareCounter+=2;
                toSort[j+2] =  toSort[j];
                j--;
            }
            toSort[j+2] = pom2;
            toSort[j+1] = pom1;
            compareCounter+=2;
            while(j>=0 && toSort[j]>pom1)
            {
                compareCounter+=2;
                toSort[j+1] = toSort[j];
                --j;
            }
            toSort[j+1] = pom1;
        }
        return compareCounter;
    };
};
#endif // SORTINSERTTRIPLE_H
