#ifndef SORTBUBBLETRIPLE_H
#define SORTBUBBLETRIPLE_H

#include "SortBehaviour.h"
class SortBubbleTriple : public SortBehaviour
{
public:
    static const SortType m_sortType=TRIPLE_BUBBLE;

    SortBubbleTriple() {};
    ~SortBubbleTriple() {};
    int sort(std::vector<int>&toSort)
    {
        int comprasions=0;
        for(unsigned int i= 0; i<toSort.size()-2; i++)//(1)
        {
            comprasions++;
            if(toSort[i] < toSort[i+1])
            {
                comprasions++;
                if(toSort[i+2]<toSort[i])
                {
                    std::swap(toSort[i],toSort[i+2]);
                }
            }
            else
            {
                comprasions++;
                if(toSort[i+1]<toSort[i+2])
                {
                    std::swap(toSort[i],toSort[i+1]);
                }
                else
                {
                    std::swap(toSort[i],toSort[i+2]);
                }
            }
            comprasions++;
            if(toSort[i+2]<toSort[i+1])
            {
                std::swap(toSort[i+1],toSort[i+2]);
            }

            unsigned int minElem=i,minElem2=i+1,maxElem=i+2;
            comprasions+=2;
            while(minElem2>1 && toSort[minElem2]<toSort[minElem-1])
            {
                comprasions+=2;
                std::swap(toSort[minElem],toSort[minElem-1]);
                std::swap(toSort[minElem2],toSort[minElem2-1]);
                minElem--;
                minElem2--;
            }
            comprasions+=2;
            while(minElem>0 && toSort[minElem]<toSort[minElem-1])
            {
                comprasions+=2;
                std::swap(toSort[minElem],toSort[minElem-1]);
                minElem--;
            }
            comprasions+=2;
            while(maxElem<(toSort.size()-1) && toSort[maxElem]>toSort[maxElem+1])
            {
                comprasions+=2;
                std::swap(toSort[maxElem],toSort[maxElem+1]);
                maxElem++;
            }
        }
        return comprasions;
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




/*
        for(int _size=0 ; _size<toSort.size(); _size+=2 )
        {
            for(int i=0; i<toSort.size()-3; i+=3)
            {
                //POSORTUJ TROJKI
                if(toSort[i] < toSort[i+1])
                {
                    if(toSort[i+2]<toSort[i])
                    {
                        std::swap(toSort[i],toSort[i+2]);
                    compare++;
                    }
                    compare++;
                }
                else
                {compare++;
                    if(toSort[i+1]<toSort[i+2])
                    {
                        std::swap(toSort[i],toSort[i+1]);

                    }
                    else
                    {
                        std::swap(toSort[i],toSort[i+2]);
                    }

                }
                if(toSort[i+2]<toSort[i+1])
                {
                    std::swap(toSort[i+1],toSort[i+2]);
                    compare++;
                }

                if(toSort[i]>toSort[i+3])
                {
                    std::swap(toSort[i+2],toSort[i+3]);
                    std::swap(toSort[i+1],toSort[i+2]);
                    std::swap(toSort[i],toSort[i+1]);
                    compare++;

                }
                else if(toSort[i+1]>toSort[i+3])
                {
                    std::swap(toSort[i+2],toSort[i+3]);
                    std::swap(toSort[i+1],toSort[i+2]);
                    compare++;
                }
                else if(toSort[i+2]>toSort[i+3])
                {
                    std::swap(toSort[i+2],toSort[i+3]);
                    compare++;

                }
            }
        }
                        std::cout<<"Triple "<<compare<<std::endl;

    }
*/


/*

for(int k=0;k<toSort.size();k+=3){
        for(int i= 0; i<toSort.size()-2; i+=3)//(1)
        {

            if(toSort[i] < toSort[i+1])
            {
                if(toSort[i+2]<toSort[i])
                {
                    std::swap(toSort[i],toSort[i+2]);
                }
            }
            else
            {
                if(toSort[i+1]<toSort[i+2])
                {
                    std::swap(toSort[i],toSort[i+1]);
                }
                else
                {
                    std::swap(toSort[i],toSort[i+2]);
                }

            }
            if(toSort[i+2]<toSort[i+1])
            {
                std::swap(toSort[i+1],toSort[i+2]);
            }

            int minElem=i,minElem2=i+1,maxElem=i+2;//(2)

            if(minElem2>1 && toSort[minElem2]<toSort[minElem-1])//(5) //N
            {
                std::swap(toSort[minElem],toSort[minElem-1]);//(6)
                std::swap(toSort[minElem2],toSort[minElem2-1]);//(6)
                minElem--;//(7)1
                minElem2--;//(7)1

            }
            else if(minElem>0 && toSort[minElem]<toSort[minElem-1])//(8) // N
            {
                std::swap(toSort[minElem],toSort[minElem-1]);//(6)
                minElem--;//(10)

            }
            if(maxElem<(toSort.size()-1) && toSort[maxElem]>toSort[maxElem+1])//(8) // N
            {
                std::swap(toSort[maxElem],toSort[maxElem+1]);//(9)
                maxElem++;//(10)

            }
        }


    }
    }




*/
