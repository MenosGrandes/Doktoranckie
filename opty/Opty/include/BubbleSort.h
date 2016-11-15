#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "../typdefs.hpp"
class BubbleSort
{
public:
    void sort(std::vector<int> &toSort)
    {
        int counter=0;
   bool swapped;
        for(VintIter i=toSort.begin(); i!=toSort.end(); i++)
        {
            for (VintIter j =(toSort.end()-1); j != i; --j)
            {
                if (*(j - 1) > *(j))
                {
                    std::iter_swap(j - 1, j);

                }
            }

        }

    }
    BubbleSort() {};
    ~BubbleSort() {};
};

#endif // BUBBLESORT_H
