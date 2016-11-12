#ifndef SORTSELECTIONTRIPLE_H
#define SORTSELECTIONTRIPLE_H

#include "../typdefs.hpp"
#include <limits>
#include <assert.h>
class SortSelectionTriple
{
public:
    SortSelectionTriple() {};
    ~SortSelectionTriple() {};
    void sort(std::vector<int>&toSort)
    {
        int a[] = {3,5,6,4,3,1,1,9};
        int N = sizeof(a)/sizeof(a[0]);
        int K = 4;

        int minHeap[K];
        //Copy first K elements in another array
        for(int i=0; i<K; i++)
        {
            minHeap[i] = a[i];
        }
        /* Build min heap with those entered elements */
        buildHeap(minHeap, K-1);

        for(int i=K; i<N; i++)
        {
            //If this number is less than root of max heap, insert it
            if(a[i] <= minHeap[0])
            {
                insertInHeap(minHeap, K-1, a[i]);
            }
        }
        //At last max heap contains K smallest elements.
        std::cout<<"\n K smallest element are: ";
        for(int i=0; i<K; i++)
        {
            std::cout<<minHeap[i]<<std::endl;
        }
    }
private :

    int leftChild(int i)
    {
        return (2*i) + 1;
    }
    int rightChild(int i)
    {
        return (2*i) + 2;
    }
    int swapElements(int a[], int i, int j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    void heapify(int a[], int i, int len)
    {
        int largest = i;

        int left  = leftChild(i);
        int right = rightChild(i);

        if(left <= len && a[i] < a[left])
        {
            largest = left;
        }
        if(right <= len && a[largest] < a[right])
        {
            largest = right;
        }

        if(largest != i)
        {
            swapElements(a, i, largest);
            heapify(a, largest, len);
        }
    }

    /* This function creates a min heap from a given input array in-place */
    void buildHeap(int a[], int len)
    {
        int i = len/2 + 1;
        for(; i>=0; i--)
        {
            heapify(a, i, len);
        }
    }

    void insertInHeap(int a[], int K, int element)
    {
        a[0] = element;
        heapify(a, 0, K);
    }

};

#endif // SORTSELECTIONTRIPLE_H
