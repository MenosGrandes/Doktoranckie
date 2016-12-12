#ifndef SORTSELECTION_H
#define SORTSELECTION_H
#include <algorithm>
#include "SortBehaviour.h"
class SortSelection : public SortBehaviour
{
public:
    static const SortType m_sortType=NORMAL_SELECTION;

    SortSelection() {};
    ~SortSelection() {};
    uint256_t sort(std::vector<int> &toSort)
    {
         compareCounter=0;
        for(VintIter it = toSort.begin(); it != toSort.end()-1; ++it)
        {
            VintIter next=(it);
            std::iter_swap((std::min_element(next++,toSort.end())),it);
            compareCounter++;
        }
        return compareCounter;
    }

};

#endif // SORTSELECTION_H
