#ifndef SortInsert_H
#define SortInsert_H
#include "../typdefs.hpp"

class SortInsert
{

public:
    SortInsert() {};
    ~SortInsert() {};
    void sort(std::vector<int> &toSort)
    {
        for(int i=1; i<toSort.size(); i++)
        {
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

};

#endif // SortInsert_H
