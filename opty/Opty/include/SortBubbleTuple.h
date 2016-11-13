#ifndef SORTBUBBLETUPLE_H
#define SORTBUBBLETUPLE_H
#include "../typdefs.hpp"

/*
http://www.dreamincode.net/forums/topic/122481-finding-the-two-lowest-values-in-array/

Albo tak ze robimy pare:
4 1 6 4 1 4
1 6

teraz wieksza w lewo a mnbiejsza w prawo
1<4
1 4 6 4 1 4
teraz 6 w lewo
6>4
1 4 6 4 1 4
6>4 itd itd.
1 4 4 1 4 6
4 1 -> zamien
1 4 1 4 4 6
1<4
1 1 4 4 4 6
4 > 4 !
4 4
4<4 !
4>4 !
4 6
4<4 !
6 koncowa wiec nic.


Inne:
4 1 6 4 1 4
sortowanie par
1 4 4 6 1 4

para : 4 6
6 > 4 !-> 1 4 4 6 1 4 -> 1 4 4 1 6 4 -> 1 4 4 1 4 6
4 < 4 !-> nic nie zmieniam
para : 1 4

*/

class SortBubbleTuple
{
public:

    SortBubbleTuple() {};
    ~SortBubbleTuple() {};
    void sort(std::vector<int> &toSort)
    {

        for(int i= 0; i<(toSort.size()-1); i++)
        {
            int minElem=i,maxElem=i+1;
            if(toSort[minElem]>toSort[maxElem])
            {
                std::swap(toSort[minElem],toSort[maxElem]);
            }

            int j=i;
            while(j>0 && toSort[minElem]<toSort[minElem-1])
            {
                std::swap(toSort[minElem],toSort[minElem-1]);
                --j;
                minElem--;
            }

            int j2=i+1;
            while(j2<(toSort.size()-1) && toSort[maxElem]>toSort[maxElem+1])
            {
                std::swap(toSort[maxElem],toSort[maxElem+1]);
                ++j2;
                maxElem++;
            }

        }
    }

};

#endif // SORTBUBBLETUPLE_H
