#include "SortInsertTuple.h"

SortInsertTuple::SortInsertTuple(int n, int max):Sort(n,max) {}
SortInsertTuple::SortInsertTuple(int n, int *tab):Sort(n,tab) {}
SortInsertTuple::~SortInsertTuple() {}
/**
2 PARY
SPRAWDZAMY CZY W PARZE JEST USTAWIONE ROSNACO, JAK NIE TO ZAMIEN
potem sprawdzamy czy drugi element pierwszej pary jest mniejszy niz pierwszy element drugiej pary,
jak jest to zamieniamy miejscami,
jak nie to robimy pare przechodzac o 1 do nastepnej wartosci tablicy do tylu.
*/
void SortInsertTuple::_sort()
{
    for(int i=2; i<m_n; i++)
    {
        swapPair(i);
        int j=i-2;

        while(j>=0 )
        {
            if((j+2)<=m_n&&m_data[j+1]>m_data[j+2])
            {
                Sort::_swap(j+1,j+2);
            }
            swapPair(j+2);
            --j;
        }
    }
}
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
