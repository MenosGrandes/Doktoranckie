#ifndef SORT_H
#define SORT_H

#include "../typdefs.hpp"
#include "../conf/easylogging++.h"

#include "SortBehaviour.h"

#include "Random.h"
template <typename SortMethod,
          typename=typename std::enable_if<std::is_base_of<SortBehaviour,SortMethod>::value,bool>::type >
class Sort;



template <typename SortMethod>
class Sort<SortMethod>
{
public:
    Sort() =default;
     ~Sort()
    {
        delete m_sortMethod;

    }
    Sort(int n, int max):m_n(n)
    {
        m_data.reserve(n);
        m_compareData.reserve(n);
        for(int i=0; i<m_n; i++)
        {
            m_data.push_back(Random::getInstance().generate(1,max));
            m_compareData.push_back(m_data[i]);
        }
        m_sortMethod = new SortMethod();
    }
    Sort(std::vector<int> append):m_n(append.size()),m_data(append),m_compareData(append),m_sortMethod(new SortMethod())
    {}


    Sort(const Sort &a):m_data(a.m_data),m_compareData(a.m_compareData),m_n(a.m_n) {};
    Sort(Sort&& o):m_data(std::move(o.m_data)),m_compareData(std::move(o.m_compareData)),m_n(std::move(m_n)) { }
    Sort&operator=(const Sort& other)
    {
        if(&other == this)
        {
            return *this;
        }
        if(m_n!= other.m_n)
        {
            m_n=other.m_n;
        }
        m_data = other.m_data;
        m_compareData = other.m_compareData;

    }

    void print() const
    {
        std::cout<<"~~~~~~~~~~~~~~~~~~"<<std::endl;
        for(int i=0; i<m_n; i++)
        {
            std::cout<<m_data[i]<<",";
        }
        std::cout<<std::endl;
    }
    uint256_t _sort()
    {
        return m_sortMethod->sort(this->m_data);
    }
    bool compare()
    {
        std::sort(std::begin(m_compareData),std::end(m_compareData), std::less<int>());
        for(int i=0; i<m_n; i++)
        {
            if(m_compareData[i]!=m_data[i])
            {
                LOG(DEBUG)<<GetType()<<" "<<m_compareData[i]<<"!="<<m_data[i];
                return false;
            }
        }

        return true;
    }
    static std::string GetType()
    {
        return ToString(SortMethod::m_sortType);
    }
protected:
    int m_n;
    std::vector<int> m_data;
    std::vector<int> m_compareData;
    SortMethod* m_sortMethod;


};


#endif // SORT_H
