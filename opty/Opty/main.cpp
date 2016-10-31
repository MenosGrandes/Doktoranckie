
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
SortBubbleTuple * bst= new SortBubbleTuple(9,10);
bst->print();
bst->_sort();
bst->print();
    return 0;
}
