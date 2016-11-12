#ifndef SORTBUBBLETRIPLE_H
#define SORTBUBBLETRIPLE_H

#include "../typdefs.hpp"
class SortBubbleTriple
{
public:
    SortBubbleTriple() {};
    ~SortBubbleTriple() {};
    void sort(std::vector<int>&toSort)
    {

        for(int i= 0; i<(toSort.size()-1); i++)
        {
            int minElem=i,maxElem=i+1;
            if(toSort[minElem]>toSort[maxElem])
            {
                std::swap(toSort[minElem],toSort[maxElem]);
            }

            int j=i;
            while(j>0 && toSort[minElem]<toSort[j-1])
            {
                std::swap(toSort[j],toSort[j-1]);
                --j;
                minElem--;
            }

            int j2=i+1;
            while(j2<(toSort.size()-1) && toSort[maxElem]>toSort[j2+1])
            {
                std::swap(toSort[j2],toSort[j2+1]);
                ++j2;
                maxElem++;
            }

        }


    };

};

#endif // SORTBUBBLETRIPLE_H
