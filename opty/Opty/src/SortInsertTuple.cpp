#include "SortInsertTuple.h"

SortInsertTuple::SortInsertTuple(int n, int max):Sort(n,max){}
SortInsertTuple::SortInsertTuple(int n, int *tab):Sort(n,tab) {}
SortInsertTuple::~SortInsertTuple(){}
/**
2 PARY
SPRAWDZAMY CZY W PARZE JEST USTAWIONE ROSNACO, JAK NIE TO ZAMIEN
potem sprawdzamy czy drugi element pierwszej pary jest mniejszy niz pierwszy element drugiej pary,
jak jest to zamieniamy miejscami,
jak nie to robimy pare przechodzac o 1 do nastepnej wartosci tablicy do tylu.
*/
void SortInsertTuple::_sort()
{

    int counter=10;
    int j=0;
    for(int i=0; i<m_n; i++)
    {
        swapPair(i);
        j=i;
bool flag=true;
        while(j>=0  && flag==true)
        {

            if(m_data[j+2]<m_data[j+1])
            {
                swap(j+2,j+1);
                flag=false;
            }
            swapPair(j);

            --j;
        }
    }



}
void SortInsertTuple::swapPair(int i)
{
    if(m_data[i+1]<m_data[i])
    {
        swap(i,i+1);
    }
//ustaw rosnaco 2 pare
    if(m_data[i+3]<m_data[i+2])
    {
        swap(i+3,i+2);
    }
}
void SortInsertTuple::swap(int x,int y)
{
    int tmp=m_data[x];
    m_data[x]=m_data[y];
    m_data[y]=tmp;
}
