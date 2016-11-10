
#include "TestSort.h"
#include "Tests.hpp"
int main()
{
    srand((time(0)));

TestSort<SortNormalBubble,SortTupleBubble> sortBubbleTest;
TestSort<SortNormalInsert,SortTupleInsert> sortInsertTest;
TestSort<SortNormalSelection,SortTupleSelection> sortSelectionTest;

//std::cout<<"\t\t"<<sortBubbleTest.test(1,1111,100000)<<std::endl;
//std::cout<<"\t\t"<<sortSelectionTest.test(10,3561,10000)<<std::endl;
//    std::cout<<"\t\t"<<sortInsertTest.test(1,10000,100000)<<std::endl;
//
////
//while(1){
std::vector<int> a{6,8,2,1,5,8};
SortTripleSelection * sb= new SortTripleSelection(a);
system("cls");
sb->print();
sb->_sort();
//assert(sb->compare());
sb->print();
delete sb;



//Test();












    return 0;
}





