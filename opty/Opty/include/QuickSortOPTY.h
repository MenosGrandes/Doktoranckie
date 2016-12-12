#ifndef QUICKSORTOPTY_H
#define QUICKSORTOPTY_H

#include "SortBehaviour.h"
#define OPTY_1
class QuickSortOPTY:public SortBehaviour
{
public:
    static const SortType m_sortType=QUICK_OPTY;

    QuickSortOPTY() =default;
    ~QuickSortOPTY() =default;
    uint256_t sort(std::vector<int> &toSort)
    {
        compareCounter=0;
#ifdef OPTY_1
        quickSort(&toSort[0],0,toSort.size()-1);
#endif // OPTY_1
#ifdef OPTY_2
        quickSortIterative(&toSort[0],0,toSort.size()-1);
#endif // OPTY_2

        return compareCounter;
    }
private :
    #ifdef OPTY_1
    void quickSort(int *arr, int low, int high)
    {
        while (low < high)
        {
            /* pi is partitioning index, arr[p] is now
               at right place */
            int pi = partition(arr, low, high);


            quickSort(arr, low, pi - 1);
            compareCounter++;
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
#endif // OPTY_1
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#ifdef OPTY_2
    template<typename T>
    void quickSortIterative(T *data, size_t start, size_t end)
    {
        range stack[32];
        range *s = stack;
        s->start = start;
        s->end = end;
        s++;
        do
        {
            // dequeue the next [start, end] range of the array to sort
            s--;
            int startI = s->start, endI = s->end;
//            int count = endI - startI + 1;
            // small array optimisation
//            if(count <= 55)
//            {
//                insertionSort(data, startI, endI);
//                continue;
//            }
            // choose the middle item as pivot
            const int pivotIndex = startI + ((endI - startI) >> 1);
            // reorder these three items such that the median is at pivotIndex
            median(data[startI], data[pivotIndex], data[endI]);

            T pivot = data[pivotIndex];
            int i = startI, j = endI;
            // move all items smaller than pivot after it and larger items before it
            while(i <= j)
            {

                // look for the next item larger than pivot (going from the start)
                while(data[i] < pivot)
                {
                    compareCounter++;
                    i++;
                }
                // do the same for the next item larger than pivot (going from the end)
                while(pivot < data[j])
                {
                    compareCounter++;
                    j--;
                }
                // swap the larger and smaller items
                compareCounter++;
                if(i <= j)
                {
                    std::swap(data[i], data[j]);
                    i++;
                    j--;
                }
                compareCounter++;
            }
            // now repeat the process on all items before the pivot
            compareCounter++;
            if(startI < j)
            {
                // instead of a recursive call, enqueue the new [start, end] range
                s->start = startI;
                s->end = j;
                s++;
            }
            // and another time on all items after the pivot
            compareCounter++;
            if(i < endI)
            {
                s->start = i;
                s->end = endI;
                s++;
            }
            compareCounter++;
        }
        while(s > stack);  // as long as we have [start, end] ranges to sort
    }

    struct range
    {
        int start;
        int end;
    };

// reorder items such that a <= b <= c
    template<typename T>
    void median(T& a, T& b, T &c)
    {
        compareCounter+=3;
        if(c < a)
            std::swap(a, c);
        if(b < a)
            std::swap(a, b);
        if(c < b)
            std::swap(b, c);
    }

#endif // OPTY_2




};

#endif // QUICKSORTOPTY_H
