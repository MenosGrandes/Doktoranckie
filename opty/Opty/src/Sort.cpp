#include "Sort.h"
template <class SortMethod>
Sort<SortMethod>::Sort(int n, int max)
{
    this->m_n=n;
    m_data.reserve(n);
    compareData.reserve(n);
    for(int i=0; i<m_n; i++)
    {
        m_data.push_back(Random::getInstance().generate(1,max));
        compareData.push_back(m_data[i]);
    }
    sortMethod = new SortMethod();

}
template <class SortMethod>
Sort<SortMethod>::Sort(std::vector<int>append)
{
    this->m_n=append.size();
    m_data.reserve(append.size());
    compareData.reserve(append.size());
    m_data.insert(std::end(m_data), std::begin(append), std::end(append));
    compareData.insert(std::end(compareData), std::begin(append), std::end(append));
    sortMethod = new SortMethod();

}



template <class SortMethod>
Sort<SortMethod>::~Sort()
{
    delete sortMethod;
}
template <class SortMethod>
void Sort<SortMethod>::_sort()
{
    sortMethod->sort(this->m_data);
}
template <class SortMethod>
bool Sort<SortMethod>::compare()
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
template <class SortMethod>
void Sort<SortMethod>::print() const
{

    std::cout<<"~~~~~~~~~~~~~~~~~~"<<std::endl;
    for(int i=0; i<m_n; i++)
    {
        std::cout<<m_data[i]<<",";
    }
    std::cout<<std::endl;

}
