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
    std::cout<<"!~!~!~TESTING~!~!~!"<<std::endl;
    std::cout<<typeid(BasicSort).name()<<" "<<typeid(TupleSort).name()<<std::endl;
    Timer t;
    long long timeTuple = 0;
    long long timeNormal = 0;

    for(int i=0; i<testCounts; i++)
    {
        std::cout<<i<<std::endl;
        BasicSort *m_basicSort = new BasicSort(tabSize,max);
        TupleSort *m_tupleSort = new TupleSort(tabSize,max);

        timeNormal+=t.measureWindows(m_basicSort);
        timeTuple +=t.measureWindows(m_tupleSort);


        m_tupleSort->compare();
        m_basicSort->compare();
        delete m_basicSort;
        delete m_tupleSort;
    }
    return ((100.0f)-(float)(((timeTuple/testCounts)*100)/(timeNormal/testCounts)));


}
template class TestSort<SortSelection,SortSelectionTuple>;
template class TestSort<SortInsert,SortInsertTuple>;
template class TestSort<BubbleSort,SortBubbleTuple>;

