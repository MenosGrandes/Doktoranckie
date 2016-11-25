#ifndef TESTSORT_H
#define TESTSORT_H

#include "Random.h"
#include "Timer.h"
#include "../typdefs.hpp"
#include <cassert>
template<typename ... Dummy> class TestSort {};

template<class BasicSort,class TupleSort,class TripleSort>
class TestSort<BasicSort,TupleSort, TripleSort>
{
public:
    void test(int testCounts,std::vector<int> toSort,TEST_OPTIONS so=NON)
    {
        if(toSort.size()==0)
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
//            std::vector<int> v= Random::getInstance().generateRandomVector(1,max,tabSize);
            switch(so)
            {
            case WORST:
                std::sort(toSort.begin(),toSort.end(), std::greater<int>());
                break;
            case BEST :
                std::sort(toSort.begin(),toSort.end(), std::less<int>());
                break;
            }

            BasicSort *m_basicSort   = new BasicSort(toSort);
            TupleSort *m_tupleSort   = new TupleSort(toSort);
            TripleSort *m_tripleSort = new TripleSort(toSort);


            t_normal+=t.measureWindows<BasicSort>(m_basicSort);
            t_tuple +=t.measureWindows<TupleSort>(m_tupleSort);
            t_triple+=t.measureWindows<TripleSort>(m_tripleSort);


            assert( m_tupleSort->compare());
            assert(m_basicSort->compare());
            assert(m_tripleSort->compare());

            delete m_basicSort;
            delete m_tupleSort;
            delete m_tripleSort;

        }
        std::cout<<BasicSort::GetType()<<" "<<(t_normal)<<std::endl<<TupleSort::GetType()<<" "<<t_tuple<<std::endl<<TripleSort::GetType()<<" "<<t_triple<<std::endl;;
    }
};
//template<class BasicSort,class TupleSort>
//class TestSort<BasicSort,TupleSort>
//{
//public:
//    void test(int testCounts,const int tabSize,int max,TEST_OPTIONS so=NON)
//    {
//        if(tabSize==0)
//        {
//            std::cout<<std::endl;
//            return ;
//        }
//        Timer t;
//
//        double t_normal=0;
//        double t_tuple=0;
//
//        for(int i=0; i<testCounts; i++)
//        {
////            std::cout<<i+1<<std::endl;
//            std::vector<int> v= Random::getInstance().generateRandomVector(1,max,tabSize);
//            switch(so)
//            {
//            case WORST:
//                std::sort(v.begin(),v.end(), std::greater<int>());
//                break;
//            case BEST :
//                std::sort(v.begin(),v.end(), std::less<int>());
//                break;
//            }
//
//            BasicSort *m_basicSort   = new BasicSort(v);
//            TupleSort *m_tupleSort   = new TupleSort(v);
//
//
//            t_normal+=t.measureWindows<BasicSort>(m_basicSort);
//            t_tuple +=t.measureWindows<TupleSort>(m_tupleSort);
//
//
//            assert( m_tupleSort->compare());
//            assert(m_basicSort->compare());
//
//            delete m_basicSort;
//            delete m_tupleSort;
//
//        }
//
//        std::cout<<(t_normal)<<","<<(t_tuple)<<std::endl;
//    }
//};
template<class BasicSort>
class TestSort<BasicSort>
{
public:
    void test(int testCounts,std::vector<int> toSort,TEST_OPTIONS so=NON)
    {
        if(toSort.size()==0)
        {
            std::cout<<std::endl;
            return ;
        }
        Timer t;

        double t_normal=0;
        double t_tuple=0;
            std::cout<<BasicSort::GetType()<<" ";

        for(int i=0; i<testCounts; i++)
        {
//            std::cout<<i+1<<std::endl;
//            std::vector<int> v= Random::getInstance().generateRandomVector(1,max,tabSize);
            switch(so)
            {
            case WORST:
                std::sort(toSort.begin(),toSort.end(), std::greater<int>());
                break;
            case BEST :
                std::sort(toSort.begin(),toSort.end(), std::less<int>());
                break;
            }

            BasicSort *m_basicSort   = new BasicSort(toSort);
            t_normal+=t.measureWindows<BasicSort>(m_basicSort);

            assert(m_basicSort->compare());

            delete m_basicSort;

        }

        std::cout<<(t_normal)<<std::endl;
    }
};
#endif // TESTSORT_H
