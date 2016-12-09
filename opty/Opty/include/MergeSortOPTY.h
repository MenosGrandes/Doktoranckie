#ifndef MERGESORTOPTY_H
#define MERGESORTOPTY_H

#define COPYBY(TYPE, a, b, n) {         \
    long __n = (n) / sizeof (TYPE);     \
    register TYPE *__a = (TYPE *) (a);  \
    register TYPE *__b = (TYPE *) (b);  \
                                        \
    do {                                \
        *__a++ = *__b++;                \
    } while (--__n > 0);                \
}

#define MEMCOPY(dest, src, n) {                 \
    switch (copy_mode) {                        \
    case 1: COPYBY (long, dest, src, n); break; \
    case 2: COPYBY (int, dest, src, n); break;  \
    default: memcpy (dest, src, n);             \
    }                                           \
}
#define MID(lo, hi) (lo + ((hi - lo) >> 1))
#include "SortBehaviour.h"
#include <cstdlib>
#include <errno.h>
#include<string.h>

/*

http://jeffreystedfast.blogspot.com/2011/04/optimizing-merge-sort.html

https://www.codeplay.com/portal/optimizing-sort-algorithms-for-the-ps3-part-3-merge-sort
*/
class MergeSortOPTY : public SortBehaviour
{
public:
    MergeSortOPTY()=default;
    ~MergeSortOPTY()=default;
    int sort(std::vector<int> &toSort);
    static const SortType m_sortType=MERGE_OPTY;

protected:

private:
    void msort (void *array, void *buf, std::size_t low, std::size_t high, std::size_t size,
                int copy_mode);
    int __sort (void *base, std::size_t nmemb, std::size_t size);
    int comparatorINT(const int a,const int b);

};

#endif // MERGESORTOPTY_H
