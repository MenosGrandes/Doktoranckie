#include "SortSelectionTuple.h"

SortSelectionTuple::SortSelectionTuple(int n, int max):Sort(n,max) {}
SortSelectionTuple::~SortSelectionTuple() {}


void SortSelectionTuple::_sort()
{
#ifdef DOBLE_BURST_SELECTION_SORT
    for(unsigned minIndex = 0, maxIndex = m_n-1; minIndex < maxIndex;)
    {
        int min = m_data[minIndex];
        int max = m_data[maxIndex];
        unsigned newMinIndex = minIndex+1;
        unsigned newMaxIndex = maxIndex;

        for(unsigned index = newMinIndex; index <= newMaxIndex;)
        {
            int value = m_data[index];

            if(value <= min)
            {
                if(value < min)
                {
                    min = value;
                    newMinIndex = minIndex;
                    m_data[index] = m_data[newMinIndex];
                }
                else
                {
                    m_data[index] = m_data[newMinIndex];
                    ++index;
                }
                m_data[newMinIndex] = value;
                ++newMinIndex;
            }
            else if(value >= max)
            {
                if(value > max)
                {
                    max = value;
                    newMaxIndex = maxIndex;
                }
                m_data[index] = m_data[newMaxIndex];
                m_data[newMaxIndex] = value;
                --newMaxIndex;
            }
            else ++index;
        }
        minIndex = newMinIndex;
        maxIndex = newMaxIndex;
    }
#endif // DOBLE_BURST_SELECTION_SORT
    /*
        for(int j = 0; j < this->m_n - 1; j++)
        {
            int pmin = j;
            for(int i = j + 1; i < this->m_n; i++)
            {
                if(m_data[i] < m_data[pmin])
                {
                    pmin = i;
                }
            }
            std::swap(m_data[pmin], m_data[j]);
        }


    */
/**
wez 2 skrajne elementy i podpisz je jako element
min = element1
max = element2

1 5 2 6 9 8
min=1
max=8
w zbiorze od element1+1 do element2-1 znajdz najmniejsza i najwieksza
min = 1 max = 9
    zamien min z indeksem element1 i max z elementem w element2.
    1 5 2 6 8 9

min = 5 max = 8
po przejsciu sprawdzania min max
min = 2 max =8
    1 2 5 6 8 9
    min = 5 max =6
    1 2 5 6 8 9
    POSORTOWANE




*/
//        for(VintIter it = m_data.begin(); it != m_data.end()-1; it-=2)
//        {
//
//            VintIter minElem=std::min_element(next++,(m_data.end()-it));
//            VintIter maxElem=std::max_element(next++,(m_data.end()-it));
//
//            std::iter_swap(),it);
//        }

}
