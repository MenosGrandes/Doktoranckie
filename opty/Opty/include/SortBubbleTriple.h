#ifndef SORTBUBBLETRIPLE_H
#define SORTBUBBLETRIPLE_H

#include "../typdefs.hpp"
#include <windows.h>
class SortBubbleTriple
{
public:
    SortBubbleTriple() {};
    ~SortBubbleTriple() {};
    void sort(std::vector<int>&toSort)
    {
Sleep(10);
    std::sort(toSort.begin(),toSort.end());


    }
};
#endif

//
//for(int k=0; k<2; k++)
//        {
//            for(int i= 0; i<(toSort.size()-2); i+=2)
//            {
//
//                int minElem=i,max1Elem=i+1,max2Elem=i+2;
//                if(toSort[minElem]>toSort[max1Elem])
//                {
//
//                    std::swap(toSort[minElem],toSort[max1Elem]);
//                }
//                else if(toSort[minElem]>toSort[max2Elem])
//                {
//                    std::swap(toSort[minElem],toSort[max2Elem]);
//
//
//                }
//                if(toSort[max1Elem]>toSort[max2Elem])
//                {
//                    std::swap(toSort[max1Elem],toSort[max2Elem]);
//                }
//
//
//                int j=i;
//                while(j>0 && toSort[minElem]<toSort[j-1])
//                {
//                    std::swap(toSort[j],toSort[j-1]);
//                    --j;
//                    minElem--;
//                }
//
//                int j2=i+1;
//                while(j2<(toSort.size()-2) && toSort[max1Elem]>toSort[j2+2])
//                {
//                    std::swap(toSort[j2+1],toSort[j2+2]);
//                    std::swap(toSort[j2],toSort[j2+1]);
//
//                    j2+=2;
//                    max1Elem+=2;
//                    max2Elem++;
//
//                }
//                int j3=j2+1;
//                while(j3<(toSort.size()-1) && toSort[max2Elem]>toSort[j3+1])
//                {
//                    std::swap(toSort[j3],toSort[j3+1]);
//                    ++j3;
//                    max2Elem++;
//                }
//            }
//        }
