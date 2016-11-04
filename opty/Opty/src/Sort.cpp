#include "Sort.h"

Sort::Sort(int n, int max)
{
    this->m_n=n;
    m_data.reserve(n);
    compareData.reserve(n);
    for(int i=0; i<m_n; i++)
    {
        m_data.push_back(Random::getInstance().generate(1,max));
        compareData.push_back(m_data[i]);
    }

}

Sort::~Sort()
{
//delete[] m_data;
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
void Sort::print() const
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

//Sort::Sort(const Sort& a)
//{
//    this->m_n=a.m_n;
//    this->m_data= new int [this->m_n];
//    for(int i=0;i<this->m_n;i++)
//    {
//        this->m_data[i]=a.m_data[i];
//    }
//}
