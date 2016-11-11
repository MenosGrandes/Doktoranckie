
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
//std::cout<<"\t\t"<<sortBubbleTupleTest.test(1,1111,100000)<<std::endl;
//std::cout<<"\t\t"<<sortInsertTupleTest.test(10,3561,10000)<<std::endl;
//std::cout<<"\t\t"<<sortSelectionTupleTest.test(1,10000,100000)<<std::endl;
//
////

//std::cout<<"\t\t"<<sortSelectionTripleTest.test(100,10,10000);


for(int i=0;i<20;i++){
SortTripleSelection * sb= new SortTripleSelection(10,10);
sb->print();
sb->_sort();
//assert(sb->compare());
    sb->print();
    delete sb;

    std::cout<<"~~~~~~~~~~~~~~~"<<std::endl;
}

//
//std::vector<int> v1 {1,2,3,4,5,6,7,8};
//VintIter _beg = v1.begin();
//VintIter _beg2 = v1.begin()+4;
//
//std::iter_swap(_beg,_beg2+1);
//for(int i :v1)
//{
//    std::cout<<i<<" ";
//}
//std::cout<<std::endl;










    return 0;
}





