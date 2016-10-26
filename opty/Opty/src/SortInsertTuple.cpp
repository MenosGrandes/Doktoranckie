#include "SortInsertTuple.h"

SortInsertTuple::SortInsertTuple(int n, int max):Sort(n,max) {}
SortInsertTuple::SortInsertTuple(int n, int *tab):Sort(n,tab) {}
SortInsertTuple::~SortInsertTuple() {}
/**

*/
void SortInsertTuple::_sort()
{
    for(int g=m_n; g!=0; g--)
    {
        std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;

        print();
        int i=g;

        int first=i-1;
        int second=i-2;
        std::cout<<g<<std::endl;

        if(m_data[first]<m_data[second]) // w second jest zawsze najwieksza
        {
           // std::cout<<"swap"<<m_data[first]<<" "<<m_data[second]<<std::endl;
            Sort::_swap(second,first);

        }
        std::cout<<m_data[first]<<" "<<m_data[second]<<std::endl;
        int j=second-1;
        print();


        //std::cout<<m_data[first]<<" first"<<m_data[second]<<" second"<<std::endl;
//    std::cout<<m_data[first]<<" >"<<m_data[second-1]<<std::endl;
        while(j>=0&&m_data[second]<=m_data[j])
        {
            std::cout<<"@@@@@@@@@@@@@@@@@@@"<<std::endl;
            Sort::_swap(second,j);
            Sort::_swap(first,second);


            j--;
            first--;
            second--;
            std::cout<<j<<" ~~"<<std::endl;
            print();
//std::cout<<m_data[second]<<" "<<m_data[j]<<std::endl;
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
