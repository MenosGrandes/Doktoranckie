#include "WorstCaseHeapSort.h"
/*
http://cboard.cprogramming.com/cplusplus-programming/116807-sorting-algorithms-worst-case-input-2.html

 By the way, an already sorted array is a min-heap, so you could just use that as the worst case for HeapSort. Reverse sorted is correspondingly the best case.
*/
WorstCaseHeapSort::WorstCaseHeapSort() {}
WorstCaseHeapSort::~WorstCaseHeapSort() {}
void WorstCaseHeapSort::generate(std::vector<int>& generator) const
{

std::sort(generator.begin(),generator.end(),std::less<int>());
}

