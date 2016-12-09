#ifndef QUICKSORTOPTY_H
#define QUICKSORTOPTY_H

#include "SortBehaviour.h"
#define OPTY_2
class QuickSortOPTY:public SortBehaviour
{
public:
    static const SortType m_sortType=QUICK_OPTY;

    QuickSortOPTY() =default;
    ~QuickSortOPTY() =default;
    int sort(std::vector<int> &toSort)
    {
        this->compare=0;
#ifdef OPTY_1
        quickSort(&toSort[0],0,toSort.size()-1);
#endif // OPTY_1
#ifdef OPTY_2
        quickSortIterative(&toSort[0],0,toSort.size()-1);
#endif // OPTY_2

        return this->compare;
    }
private :
    int compare;
    void quickSort(int *arr, int low, int high)
    {
        while (low < high)
        {
            /* pi is partitioning index, arr[p] is now
               at right place */
            int pi = partition(arr, low, high);


            quickSort(arr, low, pi - 1);
            this->compare++;
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
            //this->compare+=2;
            while(i <= j && arr[i] <= pivot)
            {
                this->compare+=2;
                i++;
            }
            //this->compare+=2;
            while(i <= j && arr[j] > pivot)
            {
                this->compare+=2;
                j--;
            }
            this->compare++;
            if (i < j)
            {
                std::swap(arr[i], arr[j]);
            }
            this->compare++;

        }
        std::swap(arr[i - 1],arr[left]);
        return i - 1;
    }
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

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
            int count = endI - startI + 1;
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
                    this->compare++;
                    i++;
                }
                // do the same for the next item larger than pivot (going from the end)
                while(pivot < data[j])
                {
                    this->compare++;
                    j--;
                }
                // swap the larger and smaller items
                this->compare++;
                if(i <= j)
                {
                    std::swap(data[i], data[j]);
                    i++;
                    j--;
                }
                this->compare++;
            }
            // now repeat the process on all items before the pivot
            this->compare++;
            if(startI < j)
            {
                // instead of a recursive call, enqueue the new [start, end] range
                s->start = startI;
                s->end = j;
                s++;
            }
            // and another time on all items after the pivot
            this->compare++;
            if(i < endI)
            {
                s->start = i;
                s->end = endI;
                s++;
            }
            this->compare++;
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
        this->compare+=3;
        if(c < a)
            std::swap(a, c);
        if(b < a)
            std::swap(a, b);
        if(c < b)
            std::swap(b, c);
    }






};

#endif // QUICKSORTOPTY_H
