#include "BubbleSort.h"

BubbleSort::BubbleSort(int n, int max):Sort(n,max) {}
BubbleSort::BubbleSort(int n, int *tab):Sort(n,tab) {}
BubbleSort::~BubbleSort(){}
void BubbleSort::_sort()
{
    for (size_t i = 0; i < this->m_n - 1; ++i)
    {
        for (size_t j = this->m_n - 1; j > i; --j)
        {
            if (this->m_data[j - 1] > this->m_data[j])
            {
               std::swap(m_data[j - 1], m_data[j]);
            }
        }
    }
}
