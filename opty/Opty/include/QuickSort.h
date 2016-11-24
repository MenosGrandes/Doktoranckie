#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "../typdefs.hpp"

class QuickSort
{
public:
    void sort(std::vector<int> &toSort)
    {
        quicksort(&toSort[0],0,toSort.size()-1,toSort.size());
//        std::sort(toSort)
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
        while (i <= j)
        {
            while(i <= j && arr[i] <= pivot)
            {
                i++;
            }

            while(i <= j && arr[j] > pivot)
            {
                j--;
            }

            if (i < j)
            {
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i - 1],arr[left]);
        return i - 1;
    }

    void quicksort(int *arr, const int left, const int right, const int sz)
    {
        if (left >= right)
        {
            return;
        }
        int part = partition(arr, left, right);
        quicksort(arr, left, part - 1, sz);
        quicksort(arr, part + 1, right, sz);
    }

};

#endif // QUICKSORT_H
