#ifndef TESTSORT_H
#define TESTSORT_H
#include <type_traits>

#include "Random.h"
#include "Timer.h"
#include <cassert>
template<class BasicSort,class TupleSort,class TripleSort>
class TestSort
{
public:
    TestSort() {};
    ~TestSort() {};
    void test(int testCounts,const int tabSize,int max,TEST_OPTIONS so=NON)
    {
        if(tabSize==0)
        {
            std::cout<<std::endl;
            return ;
        }
        Timer t;

        double t_normal=0;
        double t_tuple=0;
        double t_triple=0;

        for(int i=0; i<testCounts; i++)
        {
//            std::cout<<i+1<<std::endl;
            std::vector<int> v= Random::getInstance().generateRandomVector(1,max,tabSize);
            switch(so)
            {
            case WORST:
                std::sort(v.begin(),v.end(), std::greater<int>());
                break;
            case BEST :
                std::sort(v.begin(),v.end(), std::less<int>());
                break;
            }
//            for(int g : v)
//            {
//                std::cout<<g<<" ";
//            }

            BasicSort *m_basicSort   = new BasicSort(v);
            TupleSort *m_tupleSort   = new TupleSort(v);
            TripleSort *m_tripleSort = new TripleSort(v);


            t_normal+=t.measureWindows<BasicSort>(m_basicSort);
            t_tuple +=t.measureWindows<TupleSort>(m_tupleSort);
//            t_triple+=t.measureWindows<TripleSort>(m_tripleSort);

//std::cout<<std::endl<<"PRAWIDLOWY"<<std::endl;;
//            m_tripleSort->print();

            assert( m_tupleSort->compare());
            assert(m_basicSort->compare());
//            assert(m_tripleSort->compare());

            delete m_basicSort;
            delete m_tupleSort;
            delete m_tripleSort;

        }

        std::cout<<(t_normal)<<","<<(t_tuple)<<","<<t_triple<<std::endl;


    }
};

#endif // TESTSORT_H
