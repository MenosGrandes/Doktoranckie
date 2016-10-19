#include "Sort.h"
#include <time.h>
#include <stdlib.h>
#include <time.h>
Sort::Sort(int n, int max)
{
    this->m_n=n;





    m_data = new int[this->m_n];

    for(int i=0; i<m_n; i++)
    {
        m_data[i]=rand()%max;
        compareData.push_back(m_data[i]);
    }

}

Sort::~Sort()
{
    delete [] m_data;
}
bool Sort::compare()
{
std::sort(std::begin(compareData),std::end(compareData));
for(int i=0;i<m_n;i++){
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
}
