#ifndef WORSTCASEHEAPSORT_H
#define WORSTCASEHEAPSORT_H
#include "WorstCase.h"

/*
http://cs.stackexchange.com/questions/1540/finding-a-worst-case-of-heap-sort
*/
class WorstCaseHeapSort : public WorstCase
{
public:
    WorstCaseHeapSort();
    ~WorstCaseHeapSort();
    void generate(std::vector<int> &generator);
};

#endif // WORSTCASEHEAPSORT_H
