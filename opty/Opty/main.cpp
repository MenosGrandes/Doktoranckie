
#include "TestSort.h"


int main()
{
srand((time(0)));
#ifdef TESTS
TestSort<SortInsert,SortInsertTuple> insertSortTest;
std::cout<<insertSortTest.test(1000,30000);


TestSort<SortSelection,SortSelectionTuple> selectionSortTest;
std::cout<<selectionSortTest.test(1000,30000);

#endif // TESTS
TestSort<BubbleSort,SortBubbleTuple>bubbleSortTest;
std::cout<<bubbleSortTest.test(100,10000);


    return 0;
}
