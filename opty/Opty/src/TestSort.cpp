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
float TestSort<BasicSort,TupleSort>::test(int testCounts)
{
    std::cout<<"!~!~!~TESTING~!~!~!"<<std::endl;
    Timer t;
    long long timeTuple = 0;
    long long timeNormal = 0;
    const int n = 10000;
    for(int i=0; i<testCounts; i++)
    {
        std::cout<<"test "<<i<<std::endl;
        int *tab= new int [n];
        Random::getInstance().generateRandomTab(tab,n,1,1000);
        BasicSort *m_basicSort = new BasicSort(n,tab);
        TupleSort *m_tupleSort = new TupleSort(n,tab);

        timeNormal+=t.measureWindows(m_basicSort);
        timeTuple +=t.measureWindows(m_tupleSort);
        delete tab;
        delete m_basicSort;
        delete m_tupleSort;
    }
    return ((100.0f)-(float)(((timeTuple/testCounts)*100)/(timeNormal/testCounts)));


}
template class TestSort<SortSelection,SortSelectionTuple>;
template class TestSort<SoerInsert,SortInsertTuple>;
