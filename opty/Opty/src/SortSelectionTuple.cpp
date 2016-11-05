#include "SortSelectionTuple.h"

SortSelectionTuple::SortSelectionTuple(int n, int max):Sort(n,max) {}
SortSelectionTuple::~SortSelectionTuple() {}


inline void SortSelectionTuple::_sort()
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


    3 przypadki!
    Jak najwiekszy znaleziony element jest jednoczesnie elementem poczatkowym przeszukiwanego zbioru
    8 1 5 3 2 6
    Jak najmniejszy znaleziony element jest jednoczesnie elementem ostatnim przeszukiwanego zbioru
    4 7 2 1
    Oba powyzej w polaczeniu
    8 2 4 5 5 1

    W pierwszym przypadku:
    Najpierw zamien element najwiekszy, czyli pierwszy element, z koncem
    Potem zamien element najmniejszy z poczatkiem
    W drugim przypadku:
    Najpierw zamien element najmniejszy, czyli ostatni element, z poczatkiem
    Potem najwiekszy z koncem
    W ostatnim:
    Zamien poczatek z koncem.
    */


    for(int i=0; i<this->m_n/2; i++)
    {
        const VintIter _begin = m_data.begin()+i;
        const VintIter _end   = (m_data.end()-1)-i;

        std::pair<VintIter,VintIter> _minmax=std::minmax_element(_begin,_end+1);

        if(_minmax.first == _end && _minmax.second == _begin)//jezeli najmniejsza jest na koncu a najwieksza na poczatku
        {
            std::iter_swap(_begin,(_end));
        }
        else
        {

            if(_minmax.first == _end)//jezeli najmniejsza jest na koncu
            {
                std::iter_swap(_begin,_minmax.first);
                std::iter_swap(_end,_minmax.second);
            }
            else
            {
                std::iter_swap(_end,_minmax.second);
                std::iter_swap(_begin,_minmax.first);
            }

        }

    }

}
