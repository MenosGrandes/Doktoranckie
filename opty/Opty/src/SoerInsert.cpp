#include "SoerInsert.h"

SoerInsert::SoerInsert(int n, int max):Sort(n,max){}
SoerInsert::SoerInsert(int n, int *tab):Sort(n,tab){}

SoerInsert::~SoerInsert()
{

}
void SoerInsert::_sort()
{
    int pom, j;
    for(int i=1; i<m_n; i++)
    {

        pom = m_data[i];
        j = i-1;


        while(j>=0 && m_data[j]>pom)
        {
            m_data[j+1] = m_data[j];
            --j;
        }
        m_data[j+1] = pom;
    }
}
