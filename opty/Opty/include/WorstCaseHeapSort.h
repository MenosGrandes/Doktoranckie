#ifndef WORSTCASEHEAPSORT_H
#define WORSTCASEHEAPSORT_H
#include "WorstCase.h"

/*
http://cs.stackexchange.com/questions/1540/finding-a-worst-case-of-heap-sort


http://cboard.cprogramming.com/cplusplus-programming/116807-sorting-algorithms-worst-case-input-2.html

 By the way, an already sorted array is a min-heap, so you could just use that as the worst case for HeapSort. Reverse sorted is correspondingly the best case.
*/

class WorstCaseHeapSort : public WorstCase
{
public:
    WorstCaseHeapSort() = default;
    ~WorstCaseHeapSort() = default;
    void generate(std::vector<int> &generator) const
    {
            std::sort(generator.begin(),generator.end(),std::greater<int>());

    }

};

#endif // WORSTCASEHEAPSORT_H
