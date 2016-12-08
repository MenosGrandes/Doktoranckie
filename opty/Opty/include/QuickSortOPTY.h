#ifndef QUICKSORTOPTY_H
#define QUICKSORTOPTY_H

#include "SortBehaviour.h"
class QuickSortOPTY:public SortBehaviour
{
public:
    static const SortType m_sortType=QUICK_OPTY;

    QuickSortOPTY() {};
    ~QuickSortOPTY() {};
    int sort(std::vector<int> &toSort)
    {
        quickSort(&toSort[0],0,toSort.size()-1);
        return 0;
    }
private :
    int compare=compare;
    void quickSort(int *arr, int low, int high)
    {
        while (low < high)
        {
            /* pi is partitioning index, arr[p] is now
               at right place */
            int pi = partition(arr, low, high);


            quickSort(arr, low, pi - 1);

            low = pi+1;
        }
    }
    int partition(int *arr, const int left, const int right)
    {
        const int mid = left + (right - left) / 2;
        const int pivot = arr[mid];
        // move the mid point value to the front.
        std::swap(arr[mid],arr[left]);
        int i = left + 1;
        int j = right;
        this->compare++;
        while (i <= j)
        {
            this->compare+=2;
            while(i <= j && arr[i] <= pivot)
            {
                this->compare+=2;
                i++;
            }
            this->compare+=2;
            while(i <= j && arr[j] > pivot)
            {
                compare+=2;
                j--;
            }
            compare++;
            if (i < j)
            {
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i - 1],arr[left]);
        return i - 1;
    }

};

#endif // QUICKSORTOPTY_H
