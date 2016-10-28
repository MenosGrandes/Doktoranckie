#include "SortSelectionTuple.h"

SortSelectionTuple::SortSelectionTuple(int n, int* tab):Sort(n,tab) {}
SortSelectionTuple::SortSelectionTuple(int n, int max):Sort(n,max) {}
SortSelectionTuple::~SortSelectionTuple() {}

//min and max
void SortSelectionTuple::_sort()
{

    for(int j = 0; j < this->m_n/2; j++)
    {
        std::cout<<"j="<<j<<std::endl;
        int pmin = j;
        int pmax = (this->m_n-1)-j;
                    std::cout<<"pmin index="<<pmin<<" "<<m_data[pmin]<<std::endl;
                    std::cout<<"pmax index="<<pmax<<" "<<m_data[pmax]<<std::endl;

        for(int i = j+1 ; i < this->m_n-j-1; i++)
        {
            std::cout<<"i="<<i<<std::endl;
            //find min
            if(m_data[i] < m_data[pmin])
            {
                pmin = i;
            }
            //find max
            if(m_data[i]>m_data[pmax])
            {
                pmax = i;
            }
        }

        /*Musi byc sprawdzanie kolejnosci przenoszenia.
       jak mamy koncowa pare 54 to wtedy chcemy zamienic 5 z 4 a potem jeszcze raz 4 z 5 i mamy to samo.
         */

        std::cout<<pmax<<std::endl;
        std::swap(m_data[pmin], m_data[j]);

        std::swap(m_data[pmax], m_data[this->m_n -j-1]);


        print();
    }
}
