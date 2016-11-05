#ifndef SORT_H
#define SORT_H

#include <algorithm>
#include <functional>
#include <vector>
#include "Random.h"
class Sort
{
public:
    Sort(int n, int max);

    virtual ~Sort();
    virtual void _sort()=0;
    void print() const;

    bool compare();
protected:
    //int * m_data;
    std::vector<int> m_data;
    std::vector<int> compareData;
    int m_n;
    void _swap(int x,int y);
private:
    Sort(const Sort &a):m_data(a.m_data),compareData(a.compareData),m_n(a.m_n) {};
    Sort(Sort&& o):m_data(std::move(o.m_data)),compareData(std::move(o.compareData)),m_n(std::move(m_n)){ }

};

#endif // SORT_H
