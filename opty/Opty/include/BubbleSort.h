#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "SortBehaviour.h"
class BubbleSort : public SortBehaviour
{
public:
    static const SortType m_sortType=NORMAL_BUBBLE;

    BubbleSort() {};
    ~BubbleSort() {};
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

};

#endif // BUBBLESORT_H
