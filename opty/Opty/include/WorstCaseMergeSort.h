#ifndef WORSTCASEMERGESORT_H
#define WORSTCASEMERGESORT_H
#include "WorstCase.h"
/*
http://www.geeksforgeeks.org/find-a-permutation-that-causes-worst-case-of-merge-sort/
*/
class WorstCaseMergeSort : public WorstCase
{
public:
    WorstCaseMergeSort();
    ~WorstCaseMergeSort();
    void generate(std::vector<int> &generator);
private:
    int join(int arr[], int left[], int right[],int l, int m, int r);
    int split(int arr[], int left[], int right[],int l, int m, int r);
    int generateWorstCase(int arr[], int l, int r);
};

#endif // WORSTCASEMERGESORT_H
