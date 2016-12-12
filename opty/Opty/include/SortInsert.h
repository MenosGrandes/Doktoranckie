#ifndef SortInsert_H
#define SortInsert_H
#include "SortBehaviour.h"
class SortInsert : public SortBehaviour
{

public:
    static const SortType m_sortType=NORMAL_INSERT;

    SortInsert() {};
    ~SortInsert() {};
    uint256_t sort(std::vector<int> &toSort)
    {
         compareCounter=0;
        for(unsigned int i=1; i<toSort.size(); i++)
        {
            const int pom = toSort[i];
            int j = i-1;
            compareCounter++;
            while(j>=0 && toSort[j]>pom)
            {
                compareCounter++;
                toSort[j+1] = toSort[j];
                --j;
            }
            toSort[j+1] = pom;
        }
        return compareCounter;
    }

};

#endif // SortInsert_H
