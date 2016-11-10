
#include "TestSort.h"
#include "Tests.hpp"


#include "BubbleSort.h"
#include "SortInsert.h"
#include "SortSelection.h"

#include "SortSelectionTuple.h"
#include "SortBubbleTuple.h"
#include "SortInsertTuple.h"

#include "SortSelectionTriple.h"
#include "SortInsertTriple.h"
#include "SortBubbleTriple.h"


/*NORMAL*/
typedef Sort<BubbleSort> SortNormalBubble;
typedef Sort<SortInsert> SortNormalInsert;
typedef Sort<SortSelection> SortNormalSelection;

/*TUPLES*/
typedef Sort<SortSelectionTuple> SortTupleSelection;
typedef Sort<SortBubbleTuple> SortTupleBubble;
typedef Sort<SortInsertTuple> SortTupleInsert;
/*TRIPLES*/
typedef Sort<SortInsertTriple> SortTripleInsert;
typedef Sort<SortBubbleTriple> SortTripleBubble;
typedef Sort<SortSelectionTriple> SortTripleSelection;








int main()
{
    srand((time(0)));

TestSort<SortNormalBubble,SortTupleBubble> sortBubbleTupleTest;
TestSort<SortNormalInsert,SortTupleInsert> sortInsertTupleTest;
TestSort<SortNormalSelection,SortTupleSelection> sortSelectionTupleTest;


TestSort<SortNormalSelection,SortTripleSelection> sortSelectionTripleTest;
TestSort<SortNormalInsert,SortTripleInsert>sortInsertTripleTest;
TestSort<SortNormalBubble,SortTripleBubble>sortBubbleTripleTest;
std::cout<<"\t\t"<<sortBubbleTupleTest.test(1,1111,100000)<<std::endl;
std::cout<<"\t\t"<<sortInsertTupleTest.test(10,3561,10000)<<std::endl;
std::cout<<"\t\t"<<sortSelectionTupleTest.test(1,10000,100000)<<std::endl;
//
////

//std::cout<<"\t\t"<<sortSelectionTripleTest.test(1,1000,10000);



//while(1){
//std::vector<int> a{6,8,2,1,5,8};
//SortTripleSelection * sb= new SortTripleSelection(10,10);
//system("cls");
////sb->print();
//sb->_sort();
////assert(sb->compare());
//    //sb->print();
//    delete sb;



//Test();












    return 0;
}





