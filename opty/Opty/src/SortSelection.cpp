#include "SortSelection.h"

SortSelection::SortSelection(int n, int* tab):Sort(n,tab){}
SortSelection::SortSelection(int n, int max):Sort(n,max){}
SortSelection::~SortSelection(){}

void SortSelection::_sort()
{
    int i,j,pmin;
    for(j = 0; j < this->m_n - 1; j++)
    {
        pmin = j;
        for(i = j + 1; i < this->m_n; i++)
        {
            if(m_data[i] < m_data[pmin])
            {
                pmin = i;
            }
        }
        std::swap(m_data[pmin], m_data[j]);
    }
}
