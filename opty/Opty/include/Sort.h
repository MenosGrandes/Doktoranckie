#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>


#include "Random.h"
class Sort
{
public:
    Sort(int n, int max);
    Sort(int n,int *tab);

    virtual ~Sort();
    virtual void _sort()=0;
    void print() const;

    bool compare();
protected:
     int * m_data;
    //std::vector<int> m_data;
    std::vector<int> compareData;
    int m_n;
    void _swap(int x,int y);
    private:
 Sort(const Sort &a){};


};

#endif // SORT_H
