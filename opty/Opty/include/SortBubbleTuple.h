#ifndef SORTBUBBLETUPLE_H
#define SORTBUBBLETUPLE_H
#include "SortBehaviour.h"

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

class SortBubbleTuple : public SortBehaviour
{
public:
    static const SortType m_sortType=TUPLE_BUBBLE;

    SortBubbleTuple() {};
    ~SortBubbleTuple() {};
    uint256_t sort(std::vector<int> &toSort)
    {
         compareCounter=0;
        //const int _end=ceil(toSort.size()-(toSort.size()*0.1));
        for(unsigned int i= 0; i<toSort.size()-1; i++)//(1)
        {
            unsigned int minElem=i,maxElem=i+1;//(2)
            compareCounter++;
            if(toSort[minElem]>toSort[maxElem])//(3)
            {
                std::swap(toSort[minElem],toSort[maxElem]);//(4)
            }
            compareCounter+=2;
            while(minElem>0 && toSort[minElem]<toSort[minElem-1])//(5) //N
            {
                compareCounter+=2;
                std::swap(toSort[minElem],toSort[minElem-1]);//(6)
                minElem--;//(7)1
            }
            compareCounter+=2;
            while(maxElem<(toSort.size()-1) && toSort[maxElem]>toSort[maxElem+1])//(8) // N
            {
                compareCounter+=2;
                std::swap(toSort[maxElem],toSort[maxElem+1]);//(9)
                maxElem++;//(10)
            }
        }
        return compareCounter;

//        for(int _size=0 ; _size<toSort.size(); _size+=2)
//        {
//            for(int i=0; i<toSort.size()-2; i+=2)
//            {
//                if(toSort[i] > toSort[i+1])
//                {
//                    std::swap(toSort[i],toSort[i+1]);
//                }
//
//                if(toSort[i]>toSort[i+2]) // cost tu nie tak
//                {
//                    std::swap(toSort[i+1],toSort[i+2]);
//                    std::swap(toSort[i],toSort[i+1]);
//                }
//                else if(toSort[i+1]>toSort[i+2])
//                {
//                    std::swap(toSort[i+1],toSort[i+2]);
//
//                }
//
//            }
//
//        }


    }
};

#endif // SORTBUBBLETUPLE_H
