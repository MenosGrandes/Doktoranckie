#ifndef SHELLSORT_H
#define SHELLSORT_H
/*
http://algs4.cs.princeton.edu/21elementary/Shell.java.html
*/
#include "SortBehaviour.h"
class ShellSort : public SortBehaviour
{
public:
    static const SortType m_sortType=SHELL;

    ShellSort():m_idx(0),m_cnt(0)
    {


    }
    uint256_t sort( std::vector<int>&toSort)
    {
        compareCounter = 0;

        int iter = 0;
        for(int i=0;i<9;i++)
        {
            if(m_gap[i]<toSort.size())
            {

                iter=i;
                break;
            }
        }
        int h = m_gap[iter];

        while (h >= 1)
        {
            compareCounter++;
            for (int i = h; i < toSort.size(); i++)
            {
                compareCounter+=2;
                for (int j = i; j >= h && (toSort[j]< toSort[j-h]); j -= h)
                {
                    compareCounter++;
                    int swap = toSort[j];
                    toSort[j] = toSort[j-h];
                    toSort[j-h] = swap;
                }
            }
            h =m_gap[iter++];
        }



        return compareCounter;
    }

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
                compareCounter++;
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
            compareCounter+=2;
            if( sorted && m_idx == 8 )
            {
                break;
            }
        }
    }
    int m_gap[9]= {1750,701,301,132,57,23,10,4,1}, m_idx, m_cnt;
};

#endif // SHELLSORT_H
