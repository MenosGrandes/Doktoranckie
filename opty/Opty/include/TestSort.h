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
    std::string getType()
    {
        return BasicSort::GetType();
    }
    double test(int testCounts,int sizeOfVector,TEST_OPTIONS so)
    {

        Timer t;

        double t_normal=0;

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

            t_normal+=t.measureWindows<BasicSort>(m_basicSort);

            assert(m_basicSort->compare());

            delete m_basicSort;
        }

        return (t_normal/testCounts);
    }
};
#endif // TESTSORT_H
