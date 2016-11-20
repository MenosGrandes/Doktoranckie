#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "../typdefs.hpp"
class BubbleSort
{
public:
    void sort(std::vector<int> &toSort)
    {
//        int compare=0;
        for(VintIter i=toSort.begin(); i!=toSort.end(); i++)
        {
            for (VintIter j =(toSort.end()-1); j != i; --j)
            {

                if (*(j - 1) > *(j))
                {
                    std::iter_swap(j - 1, j);
//                    compare++;

                }
            }

        }
//        std::cout<<"Normal"<<compare<<std::endl;

    }
    BubbleSort() {};
    ~BubbleSort() {};
};

#endif // BUBBLESORT_H
