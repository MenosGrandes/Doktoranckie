#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "../typdefs.hpp"
class BubbleSort
{
public:
    void sort(std::vector<int> &toSort)
    {
        for (int i = 0; i < (toSort.size() - 1); ++i)
        {
            for (int j = (toSort.size() - 1); j > i; --j)
            {
                if (toSort[j - 1] > toSort[j])
                {
                    std::swap(toSort[j - 1], toSort[j]);
                }
            }
        }
    }
    BubbleSort(){};
    ~BubbleSort(){};
};

#endif // BUBBLESORT_H
