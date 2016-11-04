#include "SortInsertTuple.h"

SortInsertTuple::SortInsertTuple(int n, int max):Sort(n,max) {}
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
const int sizeOfArray=m_n-(m_n&1);
//
    for(int i=0; i<sizeOfArray; i+=2)
    {
        if(m_data[i] > m_data[i+1])
        {
            const int tmp=m_data[i];
            m_data[i]=m_data[i+1];
            m_data[i+1]=tmp;
        }
    }

    for(int i=2; i<sizeOfArray; i+=2)
    {
        const int pom1 = m_data[i];
        const int pom2 = m_data[i+1];

        int j = i-1;

        while(j>=0 && m_data[j]>pom2)
        {
            m_data[j+2] = m_data[j+1] = m_data[j];
            j--;
        }
        m_data[j+2] = pom2;
        m_data[j+1] = pom1;

        while(j>=0 && m_data[j]>pom1)
        {
            m_data[j+1] = m_data[j];
            --j;
        }
        m_data[j+1] = pom1;
    }
    if(m_n&1)
    {
        const int pom = m_data[m_n-1];
        int k = m_n-2;
        while(k>=0 && m_data[k]>pom)
        {
            m_data[k+1] = m_data[k];
            --k;
        }
        m_data[k+1] = pom;
    }

}


