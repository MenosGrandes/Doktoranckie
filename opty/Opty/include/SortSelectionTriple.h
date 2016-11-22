#ifndef SORTSELECTIONTRIPLE_H
#define SORTSELECTIONTRIPLE_H

#include "../typdefs.hpp"
#include <assert.h>
class SortSelectionTriple
{
public:
    SortSelectionTriple() {};
    ~SortSelectionTriple() {};
    void sort(std::vector<int>&toSort)
    {

//
//        int vectorSize=0;
//
//        if(toSort.size()%2!=0)
//        {
//            vectorSize++;
//            std::iter_swap((std::min_element(toSort.begin(),toSort.end())),toSort.begin());
//        }
//
//
//        int _end = toSort.size()-1;
//        while (vectorSize < (_end))
//        {
//            int _min1=vectorSize,_min2=vectorSize+1,_max=_end-1;
//            for (int i = (vectorSize); i <= _end; ++i)
//            {
////                std::cout<<toSort[i]<<" ";
//                if ((toSort[i]) < (toSort[_min1]) )
//                {
//                    _min2=_min1;
//                    _min1 = i;
//                }
//                else if(toSort[i] < toSort[_min2] )
//                {
//                    _min2=i;
//                }
//                else if ((toSort[i]) > (toSort[_max]))
//                {
//                    _max = i;
//                }
//            }
////          std::cout<<std::endl<<"MIN: "<<toSort[_min1]<<"i="<<_min1<<" "<<toSort[_min2]<<"i="<<_min2<<" "<<toSort[_max]<<"i="<<_max<<std::endl;
////            assert(_min1!=_min2!=_max);
////            assert(_min1!=_max);
////            assert(_min2!=_max);
////            assert(_max!=_min2);
//
//            vectorSize+=2;
//            --_end;
//        }
//
//





    int j, s, temp;
    int minInd1, minInd2, minInd3;

   for(s=0; s<(toSort.size()-1); s+=2)
   {
       minInd1=s;
       minInd2=s+1;
       minInd3=s+2;


        for (j=s; j<toSort.size(); j++)
        {


            if(toSort[minInd1]>toSort[j])
            {
                minInd3 = minInd2;
                minInd2 = minInd1;
                minInd1=j;

            }
            else if(toSort[minInd2]>toSort[j] && j!=minInd1)
            {
                minInd3 = minInd2;
                minInd2=j;
            }
            else if(toSort[minInd3]>toSort[j]&& j!=minInd2 && j!=minInd1)
            {
                minInd3=j;
            }
        }

        std::swap(toSort[s], toSort[minInd1]);
        if(minInd2!=s)
        std::swap(toSort[s+1], toSort[minInd2]);
        if(minInd3!=s+1 && minInd3!=s)
        std::swap(toSort[s+2], toSort[minInd3]);


    }
    //    if(temp==-1)
      //     {
        //       s=n;
          // }



    }

};
/*
#ifndef SORTSELECTIONTRIPLE_H
#define SORTSELECTIONTRIPLE_H

#include "../typdefs.hpp"
#include <assert.h>
class SortSelectionTriple
{
public:
    SortSelectionTriple() {};
    ~SortSelectionTriple() {};
   void sort(std::vector<int> &toSort)
    {

        int vectorSize=0;

        if(toSort.size()%2!=0)
        {
            vectorSize++;
            std::iter_swap((std::min_element(toSort.begin(),toSort.end())),toSort.begin());
        }
        int vectorSize = vectorSize;
        int _end = toSort.size()-1;
        while (vectorSize < _end)
        {
            int _min=vectorSize,_max=_end;
            for (int i = vectorSize; i < _end; ++i)
            {
                if (toSort[i] < toSort[_min])
                {
                    _min = i;
                }
                else if (toSort[i]> toSort[_max])z
                {
                    _max = i;
                }
            }
            std::swap(toSort[_min],toSort[vectorSize]);
            if(vectorSize==_max)
            {
                _max=_min;
            }
            std::swap(toSort[_max],toSort[_end]);
            ++vectorSize;
            --_end;
        }
    }
};

#endif // SORTSELECTIONTRIPLE_H




*/



#endif // SORTSELECTIONTRIPLE_H
