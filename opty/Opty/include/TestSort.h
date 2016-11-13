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
    float test(int testCounts,const int tabSize,int max,long long &normal,long long &_reference,TEST_OPTIONS so=NON)
    {
//        std::cout<<"\t!~!~!~TESTING~!~!~!"<<std::endl;
        Timer t;

normal=0;
_reference=0;

        for(int i=0; i<testCounts; i++)
        {
//            std::cout<<i+1<<std::endl;
            std::vector<int> v= Random::getInstance().generateRandomVector(1,max,tabSize);
            switch(so)
            {
                case WORST: std::sort(v.begin(),v.end(), std::greater<int>());break;
                case BEST :std::sort(v.begin(),v.end(), std::less<int>());break;
            }

            BasicSort *m_basicSort = new BasicSort(v);
            TupleSort *m_tupleSort = new TupleSort(v);

//            m_tupleSort->print();

            normal+=t.measureWindows<BasicSort>(m_basicSort);
            _reference +=t.measureWindows<TupleSort>(m_tupleSort);
//            m_tupleSort->print();

            assert( m_tupleSort->compare());
            assert(m_basicSort->compare());
//            m_basicSort->print();
            delete m_basicSort;
            delete m_tupleSort;

        }
        if(normal==0 || _reference == 0)
        {



        std::cout<<(normal)<<","<<(_reference)<<std::endl;

            return 0;
        }
        std::cout<<(normal/testCounts)<<","<<(_reference/testCounts)<<std::endl;

        //std::cout<<std::endl<<"\t"<<typeid(BasicSort).name()<<"  "<<(normal/testCounts)<<std::endl<<"\t"<<typeid(TupleSort).name()<<"  "<<(_reference/testCounts)<<std::endl;
        return ((100.0f)-(float)(((_reference/testCounts)*100)/(normal/testCounts))); ;

    }
};

#endif // TESTSORT_H
