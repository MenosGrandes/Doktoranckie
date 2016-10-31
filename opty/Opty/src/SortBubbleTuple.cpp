#include "SortBubbleTuple.h"

SortBubbleTuple::SortBubbleTuple(int n, int max):Sort(n,max) {}
SortBubbleTuple::SortBubbleTuple(int n, int *tab):Sort(n,tab) {}
SortBubbleTuple::~SortBubbleTuple() {}



/**
42517 425
24517 451
21457 457
12457


*/
void SortBubbleTuple::_sort()
{
    for (size_t i = 0; i < this->m_n/2; ++i)
    {
        bool change = false;
                for (int j = i; j < m_n - i - 1; j++) { //one way
            if (m_data[j] > m_data[j+1]) {
                int tmp = m_data[j];
                m_data[j] = m_data[j+1];
                m_data[j+1] = tmp;
                change = true;
            }
        }
        for (int j = m_n - 2 - i; j > i; j--) { //and back
            if (m_data[j] < m_data[j-1]) {
                int tmp = m_data[j];
                m_data[j] = m_data[j-1];
                m_data[j-1] = tmp;
                change = true;
            }
        }
        if(!change) break; //block (break if no element was swapped - the m_data is sorted)

    }

}
