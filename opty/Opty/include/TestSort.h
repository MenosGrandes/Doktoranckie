#ifndef TESTSORT_H
#define TESTSORT_H
#include <type_traits>

#include "Random.h"
#include "Timer.h"
#include <cassert>
template<class BasicSort,class TupleSort>
class TestSort
{
public:
    TestSort() {};
    ~TestSort() {};
    float test(int testCounts,const int tabSize,int max)
    {
        std::cout<<"\t!~!~!~TESTING~!~!~!"<<std::endl;
        Timer t;

        long long timeTuple = 0;
        long long timeNormal = 0;

        for(int i=0; i<testCounts; i++)
        {
            std::cout<<i+1<<std::endl;
            std::vector<int> v= Random::getInstance().generateRandomVector(1,max,tabSize);
            BasicSort *m_basicSort = new BasicSort(v);
            TupleSort *m_tupleSort = new TupleSort(v);


            timeNormal+=t.measureWindows<BasicSort>(m_basicSort);
            timeTuple +=t.measureWindows<TupleSort>(m_tupleSort);

            assert( m_tupleSort->compare());
            assert(m_basicSort->compare());
            delete m_basicSort;
            delete m_tupleSort;
        }
        if(timeNormal==0 || timeTuple == 0)
        {
            return 0;
        }
        std::cout<<std::endl<<"\t"<<typeid(BasicSort).name()<<"  "<<(timeNormal/testCounts)<<std::endl<<"\t"<<typeid(TupleSort).name()<<"  "<<(timeTuple/testCounts)<<std::endl;
        return ((100.0f)-(float)(((timeTuple/testCounts)*100)/(timeNormal/testCounts))); ;

    }
};

#endif // TESTSORT_H
