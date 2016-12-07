#ifndef WORSTCASEMERGESORT_H
#define WORSTCASEMERGESORT_H
#include "WorstCase.h"
/*
http://www.geeksforgeeks.org/find-a-permutation-that-causes-worst-case-of-merge-sort/
albo
http://stackoverflow.com/questions/24594112/when-will-the-worst-case-of-merge-sort-occur
*/
class WorstCaseMergeSort : public WorstCase
{
public:
    WorstCaseMergeSort();
    ~WorstCaseMergeSort();
    void generate(std::vector<int> &generator);
private:
void seperate(std::vector<int> &arr);
void merge(std::vector<int> &arr , std::vector<int> & left, std::vector<int> & right);

};

#endif // WORSTCASEMERGESORT_H
