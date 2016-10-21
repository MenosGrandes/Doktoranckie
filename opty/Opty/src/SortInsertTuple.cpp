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
    for(int i=1; i<m_n; i+=2)
    {
        swapPair(i);
        //j=i-2;

//        while(j>=0  )
//        {
////std::cout<<m_data[j+2]<<" j+2"<<std::endl;
//            if(m_data[j+2]<m_data[j+1])
//            {
//                swap(j+2,j+1);
//
//            }
//            swapPair(j);
//
//            --j;
//        }


    }



}
bool SortInsertTuple::swapPair(int i)
{
    std::cout<<i<<"~~\n";
    bool ret = true;

    std::cout<<m_data[i+1]<<" @ "<<m_data[i+2]<<std::endl;
    std::cout<<m_data[i-1]<<" ! "<<m_data[i]<<std::endl;


    if(m_data[i-1]<m_data[i])
    {
//std::cout<<m_data[i-1]<<" ! "<<m_data[i]<<std::endl;
       // swap(i-1,i);
        ret=false;
    }
//ustaw rosnaco 2 pare
    if((i+2)<m_n &&m_data[i+1]>m_data[i+2])
    {
//        std::cout<<m_data[i+1]<<" @ "<<m_data[i+2]<<std::endl;

       // swap(i+1,i+2);
        ret=false;
    }

    return ret;
}
void SortInsertTuple::swap(int x,int y)
{
    int tmp=m_data[x];
    m_data[x]=m_data[y];
    m_data[y]=tmp;
}
