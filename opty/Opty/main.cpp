
#include "TestSort.h"


int main()
{
    srand((time(0)));

TestSort<SortNormalBubble,SortTupleBubble> sortBubbleTest;
TestSort<SortNormalInsert,SortTupleInsert> sortInsertTest;
TestSort<SortNormalSelection,SortTupleSelection> sortSelectionTest;

std::cout<<"\t\t"<<sortBubbleTest.test(1,30000,100000)<<std::endl;
//std::cout<<"\t\t"<<sortSelectionTest.test(10,3560,10000)<<std::endl;
//std::cout<<"\t\t"<<sortInsertTest.test(2,pow(2,16),100000)<<std::endl;
//
////
//while(1){
//SortTupleBubble*sb = new SortTupleBubble(10,10);
//system("cls");
//sb->print();
//sb->_sort();
//assert(sb->compare());
//sb->print();
//delete sb;
//}


    return 0;
}
