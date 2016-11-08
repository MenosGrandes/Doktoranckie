#include "TestSort.h"
template<class BasicSort,class TupleSort>
TestSort<BasicSort,TupleSort>::TestSort()
{

}
template<class BasicSort,class TupleSort>
TestSort<BasicSort,TupleSort>::~TestSort()
{


}
template<class BasicSort,class TupleSort>
float TestSort<BasicSort,TupleSort>::test(int testCounts,const int tabSize,int max )
{
    std::cout<<"\t!~!~!~TESTING~!~!~!"<<std::endl;
   // std::cout<<typeid(BasicSort).name()<<" "<<typeid(TupleSort).name()<<std::endl;
    Timer t;

    long long timeTuple = 0;
    long long timeNormal = 0;

    for(int i=0; i<testCounts; i++)
    {
        std::cout<<i+1<<std::endl;
        BasicSort *m_basicSort = new BasicSort(tabSize,max);
        TupleSort *m_tupleSort = new TupleSort(tabSize,max);






        timeNormal+=t.measureWindows<BasicSort>(m_basicSort);
        timeTuple +=t.measureWindows<TupleSort>(m_tupleSort);

//
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
template class TestSort<SortNormalBubble,SortTupleBubble>;
template class TestSort<SortNormalInsert,SortTupleInsert>;
template class TestSort<SortNormalSelection,SortTupleSelection>;

