#ifndef BESTCASEHEAPSORT_H
#define BESTCASEHEAPSORT_H
#include "BestCase.h"
/*
http://cboard.cprogramming.com/cplusplus-programming/116807-sorting-algorithms-worst-case-input-2.html

 By the way, an already sorted array is a min-heap, so you could just use that as the worst case for HeapSort. Reverse sorted is correspondingly the best case.
*/
class BestCaseHeapSort : public BestCase
{
public:
    BestCaseHeapSort() = default;
    ~BestCaseHeapSort() = default;

    void generate(std::vector<int>& toSort) const
    {
        std::sort(toSort.begin(),toSort.end(), std::greater<int>());
    }

};

#endif // BESTCASEHEAPSORT_H
