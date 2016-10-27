#include "SortInsertTuple.h"
#include "SoerInsert.h"
#include "BubbleSort.h"
#include "Timer.h"
#include <time.h>



int main()
{

int n=8;
int * tab = new int[n];
tab[0]=9;
tab[1]=4;
tab[2]=3;
tab[3]=8;
tab[4]=2;
tab[5]=7;
tab[6]=6;
tab[7]=5;

    srand(time(0));
    SortInsertTuple *bs = new SortInsertTuple(n,tab);
   // bs->print();
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    bs->_sort();
    //bs->compare();
    bs->print();




//    int n=10000;
//    int *tab= new int[n];
//    Random::getInstance().generateRandomIntTab(n,tab,0,10000);
//
//SortInsertTuple *sInsertTuple= new SortInsertTuple(n,tab);
// SoerInsert *sInsert= new SoerInsert(n,tab);
//
//
//Timer timer;
////std::cout<<"Sort InsertTuple"<<s1Timer.measure(s1)<<std::endl;
////std::cout<<"Sort Insert"<<s1Timer.measure(si)<<std::endl;
//
//int sInsertTime =timer.measure(sInsert);
//int sInsertTupleTime =timer.measure(sInsertTuple);
//std::cout<<sInsertTime<<std::endl<<sInsertTupleTime<<std::endl;
//if(sInsertTime<sInsertTupleTime)
//{
//    std::cout<<"Sort insert Szybsze"<<std::endl;
//}
//else
//{
//        std::cout<<"Sort insertTuple Szybsze"<<std::endl;
//
//}



////

//int n=7;
//int * tab = new int[n];
//tab[0]=5;
//tab[1]=3;
//tab[2]=4;
//tab[3]=9;
//tab[4]=8;
//tab[5]=6;
//tab[6]=2;
//    std::vector<Sort*> sorts;
//    for(int i=0; i<1000; i++)
//    {
//        int max = Random::getInstance().generate(1,1000);
//        int n   = Random::getInstance().generate(1,max);
//        sorts.push_back(new SortInsertTuple(n,max));
//    }
//    for(int i=0; i<sorts.size(); i++)
//    {
//        sorts[i]->_sort();
//
//        if(!sorts[i]->compare())
//        {
//            std::cout<<"\t ERROR"<<std::endl;
//            sorts[i]->print();
//            std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
//        }
//    }


//
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
