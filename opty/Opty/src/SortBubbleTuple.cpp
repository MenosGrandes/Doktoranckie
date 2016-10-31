#include "SortBubbleTuple.h"

SortBubbleTuple::SortBubbleTuple(int n, int max):Sort(n,max) {}
SortBubbleTuple::SortBubbleTuple(int n, int *tab):Sort(n,tab) {}
SortBubbleTuple::~SortBubbleTuple(){}



/**
42517 425
24517 451
21457 457
12457


*/
void SortBubbleTuple::_sort()
{
    for (size_t i = 0; i < this->m_n - 1; ++i)
    {
        for (size_t j = this->m_n - 1; j > i; j-=2)
        {

        int first=m_data[j];
        int second=m_data[j-1];
        int third=m_data[j-2];

        if(first>second)
        {
        std::swap(m_data[j],m_data[j-1]);
        }

        if(second>third)
        {
             std::swap(m_data[j-1],m_data[j-2]);
        }

        }
    }

}
