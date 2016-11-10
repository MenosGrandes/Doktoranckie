#ifndef SORT_H
#define SORT_H

#include <algorithm>
#include <functional>
#include <vector>

#include "BubbleSort.h"
#include "SortInsert.h"
#include "SortSelection.h"

#include "SortSelectionTuple.h"
#include "SortBubbleTuple.h"
#include "SortInsertTuple.h"

#include "SortSelectionTriple.h"
#include "SortInsertTriple.h"
#include "SortBubbleTriple.h"
#include "Random.h"

template <class SortMethod>
class Sort
{
public:
    Sort(int n, int max)
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
    Sort(std::vector<int> append)
    {
        this->m_n=append.size();
        m_data.reserve(append.size());
        compareData.reserve(append.size());
        m_data.insert(std::end(m_data), std::begin(append), std::end(append));
        compareData.insert(std::end(compareData), std::begin(append), std::end(append));
        sortMethod = new SortMethod();
    }

    ~Sort()
    {
        delete sortMethod;
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
        sortMethod->sort(this->m_data);
    }
    bool compare()
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
protected:
    std::vector<int> m_data;
    std::vector<int> compareData;
    int m_n;
    void _swap(int x,int y);
private:
    Sort(const Sort &a):m_data(a.m_data),compareData(a.compareData),m_n(a.m_n) {};
    Sort(Sort&& o):m_data(std::move(o.m_data)),compareData(std::move(o.compareData)),m_n(std::move(m_n)) { }
    SortMethod* sortMethod;
};
///*NORMAL*/
//template class Sort<BubbleSort>;
//typedef Sort<BubbleSort> SortNormalBubble;
//
//template class Sort<SortInsert>;
//typedef Sort<SortInsert> SortNormalInsert;
//
//template class Sort<SortSelection>;
//typedef Sort<SortSelection> SortNormalSelection;
//
///*TUPLES*/
//template class Sort<SortSelectionTuple>;
//typedef Sort<SortSelectionTuple> SortTupleSelection;
//
//template class Sort<SortBubbleTuple>;
//typedef Sort<SortBubbleTuple> SortTupleBubble;
//
//template class Sort<SortInsertTuple>;
//typedef Sort<SortInsertTuple> SortTupleInsert;
///*TRIPLES*/
//template class Sort<SortInsertTriple>;
//typedef Sort<SortInsertTriple> SortTripleInsert;
//
//template class Sort<SortBubbleTriple>;
//typedef Sort<SortBubbleTriple> SortTripleBubble;
//
//template class Sort<SortSelectionTriple>;
//typedef Sort<SortSelectionTriple> SortTripleSelection;


#endif // SORT_H
