#ifndef SORT_H
#define SORT_H

#include "../typdefs.hpp"

#include "Random.h"
#include "WorstCase.h"
#include "BestCase.h"
template <class SortMethod,class WorstCaseMethod=WorstCase,class BestCaseMethod=BestCase>
class Sort
{
public:
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
        m_bestCase = new BestCaseMethod();
        m_worstCase = new WorstCaseMethod();

    }
    Sort(std::vector<int> append):m_n(append.size()),m_data(append),m_compareData(append),m_sortMethod(new SortMethod()),m_worstCase(new WorstCaseMethod()),m_bestCase(new BestCaseMethod())
    {}

    ~Sort()
    {
        delete m_sortMethod;
        delete m_bestCase;
        delete m_worstCase;
    }
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
    static std::string GetType()
    {
        return ToString(SortMethod::m_sortType);
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
    void _sort()
    {
        m_sortMethod->sort(this->m_data);
    }
    bool compare()
    {
        std::sort(std::begin(m_compareData),std::end(m_compareData), std::less<int>());
        for(int i=0; i<m_n; i++)
        {
//            std::cout<<compareData[i]<<" == "<<m_data[i]<<std::endl;
            if(m_compareData[i]!=m_data[i])
            {

                std::cout<<m_compareData[i]<<"!="<<m_data[i]<<std::endl;
                return false;
            }
        }

        return true;
    }
    void generateBest()
    {
     m_bestCase->generate(this->m_data);
    }
    void generateWorst()
    {
        m_worstCase->generate(this->m_data);
    }
protected:
    int m_n;
    std::vector<int> m_data;
    std::vector<int> m_compareData;
    SortMethod* m_sortMethod;
    WorstCaseMethod* m_worstCase;
    BestCaseMethod* m_bestCase;

};


#endif // SORT_H
