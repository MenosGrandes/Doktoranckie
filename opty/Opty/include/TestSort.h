#ifndef TESTSORT_H
#define TESTSORT_H

#include "Random.h"
#include "Timer.h"
#include "WorstCase.h"
#include "BestCase.h"
#include "../typdefs.hpp"
#include <cassert>



template<class BasicSort,class WorstCaseMethod=WorstCase,class BestCaseMethod=BestCase>
class TestSort
{
public:
        TestSort() =default;
       ~TestSort()=default;
        TestSort(TestSort&& o)=default;
        TestSort& operator=(const TestSort& other)=default;
        TestSort& operator=(TestSort&& other)=default;
        TestSort(const TestSort& a)=default;
    std::string getType()
    {
        return BasicSort::GetType();
    }
    TimeComprasions test(const int testCounts,const int sizeOfVector,const TEST_OPTIONS so)
    {

        Timer t;
        TimeComprasions tc(0,0);
        for(int i=0; i<testCounts; i++)
        {
            std::vector<int> toSort = Random::getInstance().generateRandomVector(1,1000000,sizeOfVector);

            switch(so)
            {
            case WORST:
            {
                WorstCaseMethod _wcm;
                _wcm.generate(toSort);
            }
            break;
            case BEST:
            {
                BestCaseMethod _bcm;
                _bcm.generate(toSort);
            }
            break;
            default:
                break;
            }
            BasicSort *m_basicSort   = new BasicSort(toSort);

            tc+=t.measureTimeAndComprasions<BasicSort>(m_basicSort);

            assert( m_basicSort->compare());

            delete m_basicSort;
        }
        tc/=testCounts;
        return tc;
    }

TimeComprasions test(const int testCounts,std::vector<int> &toSort,const TEST_OPTIONS so)
    {

        Timer t;
        TimeComprasions tc(0,0);
        for(int i=0; i<testCounts; i++)
        {
//            std::vector<int> toSort = Random::getInstance().generateRandomVector(1,1000000,sizeOfVector);

            switch(so)
            {
            case WORST:
            {
                WorstCaseMethod _wcm;
                _wcm.generate(toSort);
            }
            break;
            case BEST:
            {
                BestCaseMethod _bcm;
                _bcm.generate(toSort);
            }
            break;
            default:
                break;
            }
            BasicSort *m_basicSort   = new BasicSort(toSort);

            tc+=t.measureTimeAndComprasions<BasicSort>(m_basicSort);

            assert( m_basicSort->compare());

            delete m_basicSort;
        }
        tc/=testCounts;
        return tc;
    }
};
#endif // TESTSORT_H
