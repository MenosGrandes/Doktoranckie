#ifndef MERGESORT_H
#define MERGESORT_H
/*
http://codereview.stackexchange.com/questions/74410/mergesort-with-stdvector
*/
#include "SortBehaviour.h"
class MergeSort : public SortBehaviour
{
public:
    static const SortType m_sortType=MERGE;

    MergeSort() {}
    uint256_t sort(std::vector<int> &toSort)
    {
        compareCounter=0;
        _sort(toSort);
        return compareCounter;
    }
private:
    template<typename I>
    void merge(I low, I mid, I high)
    {
        I i   = low;
        I j   = mid;

        typedef typename I::value_type  value_type;
        std::vector<value_type> sorted(std::distance(low, high));
        auto x = sorted.begin();
        compareCounter+=2;
        while(i < mid && j < high)
        {
            compareCounter++;
            if (*j < *i)
            {
                // Use move semantics. So we don't copy expensive T object around.
                (*x) = std::move(*j);
                ++j;
                ++x;
            }
            else
            {
                // Put the ++ inline to show difference in readability.
                // Prefer the above to this.
                (*x++) = std::move(*i++);
            }
        }
        // Don't use a manual loop when you can use an already optimized algorithm
        x = std::move(i, mid,  x);
        x = std::move(j, high, x);
        // Now move the sorted values back.
        std::move(std::begin(sorted), std::end(sorted), low);
        compareCounter+=2;
    }

    template<typename I>
// requires std::RandomAccessIterator<I>           // Proposed C++17 syntax for concepts.
//       && std::LessThanComparable<typename I::value_type>>
    void _sort(I low, I high)
    {
        size_t size= std::distance(low, high);
        if(size <= 1)
        {
            return;
        }
        I  mid(low);
        std::advance(mid, size/2);
        _sort(low, mid);
        _sort(mid, high);
        merge(low, mid, high);
    }
    template<typename C>
    void _sort(C& v)
    {
        _sort(std::begin(v), std::end(v));
    }

};

#endif // MERGESORT_H
