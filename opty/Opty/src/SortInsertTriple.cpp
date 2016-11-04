#include "SortInsertTriple.h"


SortInsertTriple::SortInsertTriple(int n, int max):Sort(n,max) {}
SortInsertTriple::~SortInsertTriple() {}
/**

*/
 void SortInsertTriple::_sort()
{
    for(int i=0; i<m_n; i+=2)
    {
        if(m_data[i] > m_data[i+1])
        {
            const int tmp=m_data[i];
            m_data[i]=m_data[i+1];
            m_data[i+1]=tmp;
        }
    }

    for(int i=2; i<m_n; i+=2)
    {
        const int pom1 = m_data[i];
        const int pom2 = m_data[i+1];

        int j = i-1;
        while(j>=0 && m_data[j]>pom2)
        {
            m_data[j+2] = m_data[j+1] = m_data[j];
            j--;
        }
        m_data[j+2] = pom2;
        m_data[j+1] = pom1;

        while(j>=0 && m_data[j]>pom1)
        {
            m_data[j+1] = m_data[j];
            --j;
        }
        m_data[j+1] = pom1;
    }
}
