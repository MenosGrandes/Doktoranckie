#ifndef MERGESORT_H
#define MERGESORT_H

#include "SortBehaviour.h"
class MergeSort : public SortBehaviour
{
public:
    static const SortType m_sortType=MERGE;

    MergeSort() {}
    int sort(std::vector<int> &toSort)
    {
        merge_sort(toSort.begin(),toSort.end());
        return 0;
    }
private:
    void merge_sort(VintIter first, VintIter last)
    {
        if (last - first > 1)
        {
            VintIter middle = first + (last - first) / 2;
            merge_sort(first, middle);
            merge_sort(middle, last);
            std::inplace_merge(first, middle, last);
        }
    }

};

#endif // MERGESORT_H
