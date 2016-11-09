
#include "TestSort.h"


int main()
{

//
srand((time(0)));
//
//
//TestSort<SortNormalBubble,SortTupleBubble> sortBubbleTest;
//TestSort<SortNormalInsert,SortTupleInsert> sortInsertTest;
TestSort<SortNormalSelection,SortTupleSelection> sortSelectionTest;
//
//std::cout<<"\t\t"<<sortBubbleTest.test(1,10,10)<<std::endl;
std::cout<<"\t\t"<<sortSelectionTest.test(10,356,10000)<<std::endl;
////std::cout<<"\t\t"<<sortInsertTest.test(2,30000,100000)<<std::endl;
//
////
//SortTupleSelection*sb = new SortTupleSelection(6,10);
//sb->print();
//sb->_sort();
//sb->compare();
//sb->print();

    return 0;
}
