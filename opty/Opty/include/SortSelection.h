#ifndef SORTSELECTION_H
#define SORTSELECTION_H
#include "../typdefs.hpp"
#include <algorithm>
class SortSelection
{
public:
        SortSelection(){};
    ~SortSelection(){};
    void sort(std::vector<int> &toSort)
    {
        for(VintIter it = toSort.begin(); it != toSort.end()-1; ++it)
        {
            VintIter next=(it);
            std::iter_swap((std::min_element(next++,toSort.end())),it);
        }
    }

};

#endif // SORTSELECTION_H
