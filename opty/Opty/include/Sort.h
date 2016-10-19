#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <random>
#include <algorithm>
#include <functional>
#include <vector>
class Sort
{
public:
    Sort(int n, int max);
    Sort(int n);

    virtual ~Sort();
    virtual void _sort()=0;
    void print();
    friend std::ostream& operator<<(std::ostream& os, const Sort& dt);
    bool compare();
protected:
    int * m_data;
    std::vector<int> compareData;
    int m_n;


};

#endif // SORT_H
