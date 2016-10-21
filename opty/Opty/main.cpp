#include "SortInsertTuple.h"
#include "SoerInsert.h"
#include "Timer.h"
#include <time.h>



int main()
{
    int n=10000;
    int *tab= new int[n];
    Random::getInstance().generateRandomIntTab(n,tab,0,10000);

SortInsertTuple *sInsertTuple= new SortInsertTuple(n,tab);
 SoerInsert *sInsert= new SoerInsert(n,tab);


Timer timer;
//std::cout<<"Sort InsertTuple"<<s1Timer.measure(s1)<<std::endl;
//std::cout<<"Sort Insert"<<s1Timer.measure(si)<<std::endl;

int sInsertTime =timer.measure(sInsert);
int sInsertTupleTime =timer.measure(sInsertTuple);
std::cout<<sInsertTime<<std::endl<<sInsertTupleTime<<std::endl;
if(sInsertTime<sInsertTupleTime)
{
    std::cout<<"Sort insert Szybsze"<<std::endl;
}
else
{
        std::cout<<"Sort insertTuple Szybsze"<<std::endl;

}



////
//    SortInsertTuple *s= new SortInsertTuple(10,10);
//    s->print();
//    s->_sort();
//    s->compare();
////
//    if(s->compare()==true)
//    {
//        std::cout<<"Takie same";
//    }
//    else
//    {
//        std::cout<<"Inne";
//    }

//delete [] tab;
    return 0;
}
