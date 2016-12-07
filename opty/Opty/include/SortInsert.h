#ifndef SortInsert_H
#define SortInsert_H
#include "SortBehaviour.h"
class SortInsert : public SortBehaviour
{

public:
    static const SortType m_sortType=NORMAL_INSERT;

    SortInsert() {};
    ~SortInsert() {};
    int sort(std::vector<int> &toSort)
    {
        int comprasions=0;
        for(unsigned int i=1; i<toSort.size(); i++)
        {
            const int pom = toSort[i];
            int j = i-1;
            comprasions++;
            while(j>=0 && toSort[j]>pom)
            {
                comprasions++;
                toSort[j+1] = toSort[j];
                --j;
            }
            toSort[j+1] = pom;
        }
        return comprasions;
    }

};

#endif // SortInsert_H
