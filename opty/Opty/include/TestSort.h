#ifndef TESTSORT_H
#define TESTSORT_H


#include "SortInsertTuple.h"
#include "SoerInsert.h"
#include "BubbleSort.h"
#include "SortSelection.h"
#include "SortSelectionTuple.h"

#include "Timer.h"
#include "Random.h"
template<class BasicSort,class TupleSort>
class TestSort
{
    public:
        TestSort();
         ~TestSort();
        float test(int testCounts);
    protected:

    private:
};

#endif // TESTSORT_H
