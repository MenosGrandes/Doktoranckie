#ifndef TESTSORT_H
#define TESTSORT_H
#include <type_traits>

#include "SortInsertTuple.h"
#include "SortInsert.h"
#include "BubbleSort.h"
#include "SortSelection.h"
#include "SortSelectionTuple.h"
#include "BubbleSort.h"
#include "SortBubbleTuple.h"
#include "Timer.h"
#include "Random.h"
template<class BasicSort,class TupleSort>
class TestSort
{
    public:
        TestSort();
         ~TestSort();
        float test(int testCounts,const int tabSize);
    protected:

    private:
};

#endif // TESTSORT_H
