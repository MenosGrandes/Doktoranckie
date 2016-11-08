#ifndef TESTSORT_H
#define TESTSORT_H
#include <type_traits>

#include "Sort.h"
#include "Random.h"
#include "Timer.h"
#include <cassert>
template<class BasicSort,class TupleSort>
class TestSort
{
    public:
        TestSort();
         ~TestSort();
        float test(int testCounts,const int tabSize,int max);
    protected:

    private:
};

#endif // TESTSORT_H
