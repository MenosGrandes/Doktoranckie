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
    for(int i=2; i<m_n; i++)
    {

        //std::cout<<"I: \t"<<i<<std::endl;
       // print();
        swapPair(i);
        j=i-2;

        while(j>=0  )
        {
             //std::cout<<"J: \t"<<j<<std::endl;
//std::cout<<m_data[j+2]<<" j+2"<<std::endl;
            if(m_data[j+2]>m_data[j+1])
            {
                swap(j+2,j+1);
                //std::cout<<"SWAP "<<j+2<<" "<<j+1<<std::endl;
            }
            swapPair(j);

           // print();
            --j;
        }


    }




}
bool SortInsertTuple::swapPair(int i)
{
    //std::cout<<i<<"~~\n";
    bool ret = true;

//    std::cout<<m_data[i+1]<<" @ "<<m_data[i+2]<<std::endl;
//    std::cout<<m_data[i-1]<<" ! "<<m_data[i]<<std::endl;


    if(m_data[i+1]<m_data[i])
    {
//std::cout<<m_data[i-1]<<" ! "<<m_data[i]<<std::endl;
        swap(i+1,i);
        ret=false;
    }
//ustaw rosnaco 2 pare
    if((m_data[i-2]<m_data[i-1]))
    {
//        std::cout<<m_data[i+1]<<" @ "<<m_data[i+2]<<std::endl;

        swap(i-1,i-2);
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
void SortInsertTuple::swap(int x,int y,int z,int w)
{
swap(x,z);
swap(y,w);
}
