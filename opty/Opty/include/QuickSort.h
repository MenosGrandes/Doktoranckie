#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortBehaviour.h"

class QuickSort :public SortBehaviour
{
public:
    static const SortType m_sortType=QUICK;

    QuickSort() =default;
    ~QuickSort()=default;
    uint256_t sort(std::vector<int> &toSort)
    {
        compareCounter=0;
        quicksort(&toSort[0],0,toSort.size()-1);
        return compareCounter;
    };
private :
    int partition(int *arr, const int left, const int right)
    {
        const int mid = left + (right - left) / 2;
        const int pivot = arr[mid];
        // move the mid point value to the front.
        std::swap(arr[mid],arr[left]);
        int i = left + 1;
        int j = right;
        compareCounter++;
        while (i <= j)
        {
            while(i <= j && arr[i] <= pivot)
            {
                compareCounter+=2;
                i++;
            }

            while(i <= j && arr[j] > pivot)
            {
                compareCounter+=2;
                j--;
            }
            compareCounter++;
            if (i < j)
            {
                std::swap(arr[i], arr[j]);
            }
            compareCounter++;
        }
        std::swap(arr[i - 1],arr[left]);
        return i - 1;
    }

    void quicksort(int *arr, const int left, const int right)
    {
        compareCounter++;
        if (left >= right)
        {
            return;
        }
        int part = partition(arr, left, right);
        quicksort(arr, left, part - 1);
        quicksort(arr, part + 1, right);
//        std::cout<<left<<" "<<right<<" "<<part<<" "<<std::endl;
    }

//    int compare=0;
};

#endif // QUICKSORT_H
