


#include "TestSort.h"

int main()
{
srand((time(0)));
TestSort<SoerInsert,SortInsertTuple> insertSortTest;
std::cout<<insertSortTest.test(1000);


TestSort<SortSelection,SortSelectionTuple> selectionSortTest;
std::cout<<selectionSortTest.test(1000);
    return 0;
}
