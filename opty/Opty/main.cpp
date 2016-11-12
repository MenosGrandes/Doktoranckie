
#include "TestSort.h"
#include "Tests.hpp"
<<<<<<< HEAD
=======


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






>>>>>>> 6c2106290186e1a32c35f96edfbd6e5d738b32c5


#include "BubbleSort.h"
#include "SortInsert.h"
#include "SortSelection.h"

#include "SortSelectionTuple.h"
#include "SortBubbleTuple.h"
#include "SortInsertTuple.h"

#include "SortSelectionTriple.h"
#include "SortInsertTriple.h"
#include "SortBubbleTriple.h"
//
//
///*NORMAL*/
//typedef Sort<BubbleSort> SortNormalBubble;
//typedef Sort<SortInsert> SortNormalInsert;
//typedef Sort<SortSelection> SortNormalSelection;
//
///*TUPLES*/
//typedef Sort<SortSelectionTuple> SortTupleSelection;
//typedef Sort<SortBubbleTuple> SortTupleBubble;
//typedef Sort<SortInsertTuple> SortTupleInsert;
///*TRIPLES*/
//typedef Sort<SortInsertTriple> SortTripleInsert;
//typedef Sort<SortBubbleTriple> SortTripleBubble;
//typedef Sort<SortSelectionTriple> SortTripleSelection;
//
//
//
//
//
//
//
//
//int main()
//{
//    srand((time(0)));
//
//TestSort<SortNormalBubble,SortTupleBubble> sortBubbleTupleTest;
//TestSort<SortNormalInsert,SortTupleInsert> sortInsertTupleTest;
//TestSort<SortNormalSelection,SortTupleSelection> sortSelectionTupleTest;
//
//
//TestSort<SortNormalSelection,SortTripleSelection> sortSelectionTripleTest;
//TestSort<SortNormalInsert,SortTripleInsert>sortInsertTripleTest;
//TestSort<SortNormalBubble,SortTripleBubble>sortBubbleTripleTest;
////std::cout<<"\t\t"<<sortBubbleTupleTest.test(1,1111,100000)<<std::endl;
////std::cout<<"\t\t"<<sortInsertTupleTest.test(10,3561,10000)<<std::endl;
////std::cout<<"\t\t"<<sortSelectionTupleTest.test(1,10000,100000)<<std::endl;
////
//////
//
////std::cout<<"\t\t"<<sortSelectionTripleTest.test(100,10,10000);
//
//
//for(int i=0;i<1;i++){
//SortTripleSelection * sb= new SortTripleSelection(6,10);
//sb->print();
//sb->_sort();
////assert(sb->compare());
//    sb->print();
//    delete sb;
//
//    std::cout<<"~~~~~~~~~~~~~~~"<<std::endl;
//}
//
////
////std::vector<int> v1 {1,2,3,4,5,6,7,8};
////VintIter _beg = v1.begin();
////VintIter _beg2 = v1.begin()+4;
////
////std::iter_swap(_beg,_beg2+1);
////for(int i :v1)
////{
////    std::cout<<i<<" ";
////}
////std::cout<<std::endl;
//
//
////int arr[] = {1,8,4,5,12,2,5,6,7,1,90,100,100,8,34};
////
////            int temp, f, s, t;
////            f = s = t = arr[0];
////            for(int i : arr)
////            {
////                if (f < i)
////                {
////                    temp = f;
////                    f = i;
////                    s = temp;
////                }
////                if (s < i && f > i)
////                {
////                    temp = i;
////                    s = i;
////                    t = temp;
////                }
////                if (t < i && s > i)
////                {
////                    temp = i;
////                     t=i;
////                }
////            }
////
//
//
//
////std::cout<<f<<" "<<s<<" "<<t<<std::endl;
//
//
//    return 0;
//}
//
//
//
//
//

int main(){

    return 0;
}
