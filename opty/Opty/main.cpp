#include "SortInsertTuple.h"
#include <time.h>
int main()
{

srand(time(0));
//
SortInsertTuple *s= new SortInsertTuple(100,1000);

s->_sort();

if(s->compare()==true)
{
    std::cout<<"Takie same";
}
else
{
    std::cout<<"Inne";
}
    return 0;
}
