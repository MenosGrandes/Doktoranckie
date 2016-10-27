#include "Sort.h"

Sort::Sort(int n, int max)
{
    this->m_n=n;
    m_data = new int[n];
   // m_data.reserve(n);
    for(int i=0; i<m_n; i++)
    {
        m_data[i]=Random::getInstance().generate(1,max);
        compareData.push_back(m_data[i]);
    }

}
Sort::Sort(int n, int *tab)
{
    this->m_n=n;
    m_data = new int[n];
    //m_data.reserve(n);
    for(int i=0; i<m_n; i++)
    {
        m_data[i]=tab[i];
        compareData.push_back(m_data[i]);
    }

}
Sort::~Sort()
{
delete[] m_data;
}
bool Sort::compare()
{
    std::sort(std::begin(compareData),std::end(compareData), std::less<int>());
    for(int i=0; i<m_n; i++)
    {
        if(compareData[i]!=m_data[i])
        {
            std::cout<<compareData[i]<<"!="<<m_data[i]<<std::endl;
            return false;
        }
    }

    return true;

}
void Sort::print()
{

    std::cout<<"~~~~~~~~~~~~~~~~~~"<<std::endl;
    for(int i=0; i<m_n; i++)
    {
        std::cout<<m_data[i]<<",";
    }
    std::cout<<std::endl;

//    std::cout<<"@@@@@@@@@@"<<std::endl;
//    for(int i=0; i<m_n; i++)
//    {
//        std::cout<<compareData[i]<<",";
//    }
//    std::cout<<std::endl;
}
void Sort::_swap(int x,int y)
{
    int tmp=m_data[x];
    m_data[x]=m_data[y];
    m_data[y]=tmp;
}
