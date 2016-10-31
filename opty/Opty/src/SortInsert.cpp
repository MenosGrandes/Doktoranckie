#include "SortInsert.h"

SortInsert::SortInsert(int n, int max):Sort(n,max) {}
SortInsert::SortInsert(int n, int *tab):Sort(n,tab) {}
SortInsert::~SortInsert(){}
void SortInsert::_sort()
{

    for(int i=1; i<m_n; i++)
    {

        const int pom = m_data[i];
        int j = i-1;


        while(j>=0 && m_data[j]>pom)
        {
            m_data[j+1] = m_data[j];
            --j;
        }
        m_data[j+1] = pom;
    }
}
