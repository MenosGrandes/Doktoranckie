#ifndef SORTINSERTTRIPLE_H
#define SORTINSERTTRIPLE_H

#include "../typdefs.hpp"
#include "SortInsert.h"
#include "SortInsertTuple.h"
class SortInsertTriple
{
public:
    SortInsertTriple() {};
    ~SortInsertTriple() {};
    void sort(std::vector<int>&toSort)
    {

        int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,all=0;
        const int arrayDivider = (toSort.size()%3);
        if(toSort.size()%3!=0)
        {
            for(int i=1; i<arrayDivider; i++)
            {c1++;
                const int pom = toSort[i];
                int j = i-1;
                while(j>=0 && toSort[j]>pom)
                {
                    toSort[j+1] = toSort[j];
                    --j;

                }
                toSort[j+1] = pom;
            }

        }

        for(int i=arrayDivider; i<toSort.size(); i+=3)
        {
all++;
            if(toSort[i] < toSort[i+1])
            {
                c2++;
                if(toSort[i+2]<toSort[i])
                {
                    std::swap(toSort[i],toSort[i+2]);
                c3++;
                }
            }
            else
            {
                if(toSort[i+1]<toSort[i+2])
                {
                    std::swap(toSort[i],toSort[i+1]);
                }
                else
                {
                    std::swap(toSort[i],toSort[i+2]);
                }
                c4++;
            }
            if(toSort[i+2]<toSort[i+1])
            {
                std::swap(toSort[i+1],toSort[i+2]);
            c5++;
            }

            const int pom1 = toSort[i];
            const int pom2 = toSort[i+1];
            const int pom3 = toSort[i+2];

            int j = i-1;
            while(j>=0 && toSort[j]>pom3)
            {
                toSort[j+3] =  toSort[j];
                j--;
                c6++;
            }
            toSort[j+3] = pom3;
            toSort[j+2] = pom2;
            toSort[j+1] = pom1;

            while(j>=0 && toSort[j]>pom2)
            {
                toSort[j+2] =  toSort[j];
                j--;
                c7++;
            }
            toSort[j+2] = pom2;
            toSort[j+1] = pom1;

            while(j>=0 && toSort[j]>pom1)
            {
                toSort[j+1] = toSort[j];
                --j;
                c8++;
            }
            toSort[j+1] = pom1;
        }
        std::cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<" "<<c5<<" "<<c6<<" "<<c7<<" "<<c8<<" "<<all<<std::endl;
    };
};
#endif // SORTINSERTTRIPLE_H
