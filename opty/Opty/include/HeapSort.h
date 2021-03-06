#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "SortBehaviour.h"
class HeapSort : public SortBehaviour
{
public:
    static const SortType m_sortType=HEAP;

    HeapSort()=default;
    ~HeapSort()=default;
    uint256_t sort(std::vector<int>& toSort)
    {
        compareCounter = 0;
        heap_sort(toSort);
        return compareCounter;
    }

private:
    void shift_down(std::vector<int>& heap,int i, int max)
    {
        int i_big, c1, c2;
        compareCounter++;
        while(i < max)
        {
            i_big = i;
            c1 = (2*i) + 1;
            c2 = c1 + 1;
            compareCounter+=3;
            if( c1<max && heap[c1]>heap[i_big] )
            {
                i_big = c1;
            }
            if( c2<max && heap[c2]>heap[i_big] )
            {
                i_big = c2;
            }
            if(i_big == i)
            {
                return;
            }
            compareCounter++;
            std::swap(heap[i],heap[i_big]);
            i = i_big;
        }
    }

    void to_heap(std::vector<int>& arr)
    {
        int i = (arr.size()/2) - 1;
        while(i >= 0)
        {
            compareCounter++;
            shift_down(arr, i, arr.size());
            --i;
        }
    }

    void heap_sort(std::vector<int>& arr)
    {
        to_heap(arr);
        int end = arr.size() - 1;
        while (end > 0)
        {
            compareCounter++;
            std::swap(arr[0], arr[end]);
            shift_down(arr, 0, end);
            --end;
        }
    }



};

#endif // HEAPSORT_H
