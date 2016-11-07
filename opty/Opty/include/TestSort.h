#ifndef TESTSORT_H
#define TESTSORT_H
#include <type_traits>

#include "Sort.h"
#include "Timer.h"
#include "Random.h"
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
