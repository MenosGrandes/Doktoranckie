
#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <vector>
#include "Random.h"
#include <iostream>
typedef std::vector<int>::iterator VintIter;
typedef std::pair<VintIter,VintIter> VintIterPair;
//
//
//struct MinMinMax
//{
//    int min1,min2,max;
//};
//MinMinMax CreateMinMinMax(int min1,int min2,int max)
//{
//    MinMinMax a;
//    a.min1=min1;
//    a.min2=min2;
//    a.max=max;
//    return a;
//}
//bool Compare(const MinMinMax &a,const MinMinMax &a2)
//{
//    return ((a.min1==a2.min1)&&(a.min2==a2.min2)&&(a.max==a.max));
//}
//void Get2MinMax(std::vector<int>toSort,int &min1,int &min2,int &max)
//{
//    VintIter _begin = toSort.begin();
//    VintIter _end = toSort.end() - 1;
////        while (_begin < _end)
////        {
//    VintIter it=_begin;
//    VintIter _min1=it;
//    VintIter _min2=it;
//    VintIter _max=it;
//    for (it = _begin; it <= _end; ++it)
//    {
//        if ((*it) < (*_min1))
//        {
//            _min2=_min1;
//            _min1 = it;
//        }
//        else if((*it)<(*_min2)&& _min2!=_min1)
//        {
//            _min2=it;
//        }
//        else if ((*it) > (*_max))
//        {
//            _max = it;
//        }
//    }
////            std::cout<<*_min1<<*_min2<<*_max<<std::endl;
//    min1=(*_min1);
//    min2=(*_min2);
//    max=(*_max);
//}
//void Get2Min(std::vector<int>toSort,int &first,int &second)
//{
//    first =toSort[0];
//    second = toSort[0];
//    for (int i = 0; i < toSort.size() ; i ++)
//    {
//        /* If current element is smaller than first
//           then update both first and second */
//        if (toSort[i] < first)
//        {
//            second = first;
//            first = toSort[i];
//        }
//
//        /* If arr[i] is in between first and second
//           then update second  */
//        else if (toSort[i] < second && toSort[i] != first)
//        {
//            second = toSort[i];
//        }
//    }
////    std::cout<<first<<" "<<second<<"~~~~~~~~~~~~~~~"<<std::endl;
//
//}
//void Test()
//{
//    for(int i=0; i<1; i++)
//    {
//        std::vector<int> v=Random::getInstance().generateRandomVector(1,10,10);
//        for(int i : v)
//        {
//            std::cout<<i<<" ";
//        }
//        std::cout<<std::endl;
//
//
//        int min1,min2,max;
//        Get2MinMax(v,min1,min2,max);
//        MinMinMax my=CreateMinMinMax(min1,min2,max);
//
//
//        std::cout<<min1<<" "<<min2<<" "<<max<<std::endl;
//        int min11,min12,max1;
//        Get2Min(v,min11,min12);
//        max1=*std::max_element(v.begin(),v.end());
//
//        MinMinMax notMy=CreateMinMinMax(min11,min12,max1);
//
//        const char * ans = Compare(my,notMy) ? "the same" : "not the same";
//        std::cout<<"MY: "<<my.min1<<" "<<my.min2<<" "<<my.max<<std::endl;
//        std::cout<<"SYSTEM: "<<notMy.min1<<" "<<notMy.min2<<" "<<notMy.max<<std::endl;
//
//        std::cout<<ans<<std::endl;;
//    }
//}
#endif // TYPEDEFS
