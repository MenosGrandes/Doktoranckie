#include "SortInsertTuple.h"

SortInsertTuple::SortInsertTuple(int n, int max):Sort(n,max) {}
SortInsertTuple::SortInsertTuple(int n, int *tab):Sort(n,tab) {}
SortInsertTuple::~SortInsertTuple() {}
/**

*/
void SortInsertTuple::_sort()
{
    /**robimy tak jak z poprzednim
    bierz po pare liczb, nastepujacych po sobie
    4 9 3 8 2 7 6 5
    4 9 -> ustaw w kolejnosci rosnacej
    poniewaz to pierwse 2 liczby to nie ma z czym porownac wez nastepne
    3 8 -> kolejnosc rosnaca
    porownaj najwieksza z pary 3,8 z liczbami poprzedzajacymi czyli
    8< 9 - true
        4 3 8 9 2 7 6 5
    8 < 4 - false -> porownaj z mniejsza liczba
    3 < 4 - true -> koniec porownania bo doszlismy do poczatku
        3 4 8 9 2 7 6 5
    teraz nastepna para
    2 7 -> ustaw w kolejnosci rosnacej
    7 < 9
        3 4 8 2 7 9 6 5
    7 < 8
        3 4 2 7 8 9 6 5
    7 < 4 ->false zmniej porownywanie na mniejsza a w miejsce wstaw wieksza
    2 < 4
        3 2 4 7 8 9 6 5
    2 < 3
        2 3 4 7 8 9 6 5
    nastepna para
     6 5 > zmien kolejnosc na rosnaco
        2 3 4 7 8 9 5 6
    6 < 9
        2 3 4 7 8 5 6 9

    6 < 8
        2 3 4 7 5 6 8 9
    6 < 7
        2 3 4 5 6 7 8 9
    6 < 4 -> false zmien na 5
    5 < 5 -> false wiec skoncz

        2 3 4 5 6 7 8 9

    */

    for(int i=0; i<m_n; i+=2)
    {

        if(m_data[i] > m_data[i+1])
        {
            Sort::_swap(i,i+1);

        }
        int pom1 = m_data[i];
        int pom2 = m_data[i+1];
   // std::cout<<pom1<<" "<<pom2<<std::endl;
        int j = i-1;
        while(j>=0 && m_data[j]>pom2)
        {
            _swap3(j,j+1,j+2);
           // std::cout<<"\t "<<j<<std::endl;
           // print();
            --j;
        }

    //std::cout<<"Po zmianie "<<std::endl;;
        //print();
//std::cout<< j <<" "<<m_data[j]<<" "<<pom2<<std::endl;
        while(j>=0 && m_data[j]>pom1)
        {

            Sort::_swap(j+1,j);
            //print();
            --j;

        }
    }
}

//    }
//}
bool SortInsertTuple::swapPair(int i)
{
    if(m_data[i+1]<m_data[i])
    {
        Sort::_swap(i+1,i);
    }
//ustaw rosnaco 2 pare
    if((m_data[i-2]>m_data[i-1]))
    {
        Sort::_swap(i-1,i-2);
    }
    return true;
}

void SortInsertTuple::_swap(int x,int y,int z,int w)
{
    Sort::_swap(x,z);
    Sort::_swap(y,w);
}
void SortInsertTuple::_swap3(int x,int y, int z)
{
Sort::_swap(x,y);
Sort::_swap(y,z);
}
//void SortInsertTuple::swapFirst(int &i,int &first,int &second)
//{
//
//}
//void SortInsertTuple::swapSecond()
//{
//
//}
