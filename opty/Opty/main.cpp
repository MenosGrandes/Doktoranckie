#include "SortInsertTuple.h"
#include "SoerInsert.h"
#include "BubbleSort.h"
#include "Timer.h"
#include <time.h>



int main()
{

//int n=8;
//int * tab = new int[n];
//tab[0]=4;
//tab[1]=9;
//tab[2]=3;
//tab[3]=8;
//tab[4]=2;
//tab[5]=7;
//tab[6]=6;
//tab[7]=5;
//int pom1=tab[2];
//int pom2=tab[3];
//int j=1;
//
//               tab[j+1] = tab[j];
//               tab[j+2] = tab[j+1];
//            /*
//
//            Sort::_swap(x,y);
//            Sort::_swap(y,z);
//            */
//            j--;
//
//         tab[j+2] = pom2;
//         tab[j+1] = pom1;
//
//
//
//for(int i=0;i<n;i++)
//{
//    std::cout<<tab[i];
//}






long long timeInsertSortTuple = 0;
long long timeInsert = 0;
int numberOfTasks=10000;
srand(time(0));
Timer t;

int n = 100000;
int *tab= new int [n];
Random::getInstance().generateRandomTab(tab,n,1,1000);

//for(int i=0;i<numberOfTasks;i++)
//{

    //int n = Random::getInstance().generate()
    SortInsertTuple *bs = new SortInsertTuple(n,tab);
    SoerInsert *ins = new SoerInsert(n,tab);

    //bs->print();
    //std::cout<<"@@@@@@@@@@@@@@@"<<std::endl;
    timeInsertSortTuple=t.measureWindows(bs);
    timeInsert=t.measureWindows(ins);
    std::cout<<"IsertTuple "<<timeInsertSortTuple<<std::endl;
    std::cout<<"timeInsert "<<timeInsert<<std::endl;

    bs->compare();
    ins->compare();
   // bs->print();
   delete bs;
   delete ins;
   delete[] tab;
//}


    return 0;
}
