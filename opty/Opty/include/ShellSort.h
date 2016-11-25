#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "SortBehaviour.h"
class ShellSort : public SortBehaviour
{
public:
                                    static const SortType m_sortType=SHELL;

    ShellSort()
    {
        m_gap[0] = 1750;
        m_gap[1] = 701;
        m_gap[2] = 301;
        m_gap[3] = 132;
        m_gap[4] = 57;
        m_gap[5] = 23;
        m_gap[6] = 10;
        m_gap[7] = 4;
        m_gap[8] = 1;

    }
    void sort( std::vector<int>&toSort)
    {
        m_cnt = toSort.size();
        for( int x = 0; x < 9; x++ )
            if( toSort.size() > m_gap[x] )
            {
                m_idx = x;
                break;
            }

        sortIt( &toSort[0] );
    }
protected:

private:
    void sortIt( int* arr )
    {
        bool sorted = false;
        while( true )
        {
            sorted = true;
            int st = 0;
            for( int x = m_gap[m_idx]; x < m_cnt; x += m_gap[m_idx] )
            {
                if( arr[st] > arr[x] )
                {
                    std::swap( arr[st], arr[x] );
                    sorted = false;
                }
                st = x;
            }
            if( ++m_idx >= 8 )
            {
                m_idx = 8;
            }
            if( sorted && m_idx == 8 )
            {
                break;
            }
        }
    }
    int m_gap[9], m_idx, m_cnt;
};

#endif // SHELLSORT_H
