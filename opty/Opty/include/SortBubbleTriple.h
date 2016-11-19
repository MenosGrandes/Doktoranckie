#ifndef SORTBUBBLETRIPLE_H
#define SORTBUBBLETRIPLE_H

#include "../typdefs.hpp"
#include <windows.h>
#include <iostream>
class SortBubbleTriple
{
public:
    SortBubbleTriple() {};
    ~SortBubbleTriple() {};
    void sort(std::vector<int>&toSort)
    {
    for(VintIter i=toSort.begin(); i!=toSort.end(); i++)
        {
            for (VintIter j =(toSort.end()-1); j != i; --j)
            {
                if (*(j - 1) > *(j))
                {
                    std::iter_swap(j - 1, j);

                }
            }

        }
//        for(int _size=0 ; _size<toSort.size(); _size++)
//        {
//            for(int i=0; i<toSort.size()-3; i++)
//            {
//                //POSORTUJ TROJKI
//                if(toSort[i] < toSort[i+1])
//                {
//                    if(toSort[i+2]<toSort[i])
//                    {
//                        std::swap(toSort[i],toSort[i+2]);
//                    }
//                }
//                else
//                {
//                    if(toSort[i+1]<toSort[i+2])
//                    {
//                        std::swap(toSort[i],toSort[i+1]);
//                    }
//                    else
//                    {
//                        std::swap(toSort[i],toSort[i+2]);
//                    }
//
//                }
//                if(toSort[i+2]<toSort[i+1])
//                {
//                    std::swap(toSort[i+1],toSort[i+2]);
//                }
//
//                int min1=i;
//                int min2=i+1;
//                int min3=i+2;
//
//                //zamien wsztstkie 3
////                std::cout<<toSort[min3]<<" "<<toSort[min3+1]<<std::endl;
//                if(toSort[min1]>toSort[min3+1])
//                {
//                    std::swap(toSort[min3],toSort[min3+1]);
//                    std::swap(toSort[min2],toSort[min2+1]);
//                    std::swap(toSort[min1],toSort[min1+1]);
//
//                }
//                else if(toSort[min2]>toSort[min3+1]) // cost tu nie tak
//                {
//                    std::swap(toSort[min3],toSort[min3+1]);
//                    std::swap(toSort[min2],toSort[min2+1]);
//                }
//                else if(toSort[min3]>toSort[min3+1])
//                {
//                    std::swap(toSort[min3],toSort[min3+1]);
//
//                }
//
//
//
//
//            }
//
//        }
    }


};

#endif
//KOLEJNA WERSJA
//int a=0,b=0,c=0;
//        for(int i= 0; i<(toSort.size()-2); i++)//(1)
//        {
//            //posortuj 3 elementy
//            if(toSort[i] < toSort[i+1])
//            {
//                if(toSort[i+2]<toSort[i])
//                {
//                    std::swap(toSort[i],toSort[i+2]);
//                }
//            }
//            else
//            {
//                if(toSort[i+1]<toSort[i+2])
//                {
//                    std::swap(toSort[i],toSort[i+1]);
//                }
//                else
//                {
//                    std::swap(toSort[i],toSort[i+2]);
//                }
//
//            }
//            if(toSort[i+2]<toSort[i+1])
//            {
//                std::swap(toSort[i+1],toSort[i+2]);
//            }
//            //////////////////////
////min 2 elem zawsze bedzie wiekszy badz rowny min1 elem. Wiec zaczynam od niego
//            int minElem1=i,minElem2=i+1,minElem3=i+2;//(2)

//            while(minElem1>0 && toSort[minElem3]<toSort[minElem1-1])//(5) //N
//            {
//                std::swap(toSort[minElem1],toSort[minElem1-1]);//(6)
//
//
//                minElem1--;//(7)1
//                minElem2--;//(7)1
//                minElem3--;//(7)1
//                a++;
//
//            }
//
//            while(minElem1>0 && toSort[minElem2]<toSort[minElem1-1])//(5) //N
//            {
//                std::swap(toSort[minElem2],toSort[minElem2-1]);//(6)
//
//                minElem2--;//(7)1
//                minElem1--;//(7)1
//                b++;
//            }

//
//            while(minElem1>0 && toSort[minElem1]<toSort[minElem1-1])//(5) //N
//            {
//                std::swap(toSort[minElem1],toSort[minElem1-1]);//(6)
//                minElem1--;//(7)1
//                c++;
//            }
//        }
//        std::cout<<std::endl<<"a="<<a<<" b="<<b<<" c="<<c<<std::endl;
//
//    }


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
