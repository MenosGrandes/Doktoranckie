#include "SortSelectionTuple.h"

SortSelectionTuple::SortSelectionTuple(int n, int max):Sort(n,max) {}
SortSelectionTuple::~SortSelectionTuple() {}

//min and max
/**
Sortowanie przez wybieranie 2 najmniejszej  wartosci w zbiorze.



*/
void SortSelectionTuple::_sort()
{

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

}
