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
int counter=0;
        for(int i= 0; i<(toSort.size()-1); i++)//(1)
        {
            int minElem=i,maxElem=i+1;//(2)
            if(toSort[minElem]>toSort[maxElem])//(3)
            {
                std::swap(toSort[minElem],toSort[maxElem]);//(4)
                counter++;
            }

            while(minElem>0 && toSort[minElem]<toSort[minElem-1])//(5) //N
            {
                std::swap(toSort[minElem],toSort[minElem-1]);//(6)
                minElem--;//(7)1
                counter++;
            }

            while(maxElem<(toSort.size()-1) && toSort[maxElem]>toSort[maxElem+1])//(8) // N
            {
                std::swap(toSort[maxElem],toSort[maxElem+1]);//(9)
                maxElem++;//(10)
                counter++;
            }
            counter++;

        }
    std::cout<<"Operacje"<<counter<<std::endl;
    }

};

#endif // SORTBUBBLETUPLE_H
