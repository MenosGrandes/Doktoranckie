#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "SortBehaviour.h"
class ShellSort : public SortBehaviour
{
public:
    static const SortType m_sortType=SHELL;

    ShellSort():m_idx(0),m_cnt(0)
    {


    }
    int sort( std::vector<int>&toSort)
    {
        m_cnt = toSort.size();
        for( unsigned int x = 0; x < 9; x++ )
            if( toSort.size() > m_gap[x] )
            {
                m_idx = x;
                break;
            }

        sortIt( &toSort[0] );

        return 0;
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
    int m_gap[9]= {1750,701,3010,132,57,23,10,4,1}, m_idx, m_cnt;
};

#endif // SHELLSORT_H
