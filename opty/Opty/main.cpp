
#include "TestSort.h"


int main()
{
srand((time(0)));
#ifdef TESTS
TestSort<SortInsert,SortInsertTuple> insertSortTest;
std::cout<<insertSortTest.test(1000,30000);


TestSort<SortSelection,SortSelectionTuple> selectionSortTest;
std::cout<<selectionSortTest.test(1000,30000);

TestSort<BubbleSort,SortBubbleTuple>bubbleSortTest;
std::cout<<bubbleSortTest.test(100,10000);
#endif // TESTS


//TestSort<SortInsert,SortInsertTuple> insertSortTest;
//std::cout<<insertSortTest.test(1,30000,100000);
////
//SortSelection *sit = new SortSelection(10000,1000);
////sit->print();
//sit->_sort();
//sit->compare();
////sit->print();

TestSort<SortSelection,SortSelectionTuple> selectionSortTest;
std::cout<<selectionSortTest.test(1,30000,1000);

TestSort<SortInsert,SortInsertTuple> insertSortTest;
std::cout<<insertSortTest.test(1,30000,30000);

    return 0;
}
