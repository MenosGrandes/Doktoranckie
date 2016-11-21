#ifndef TESTS_H
#define TESTS_H
#include "typdefs.hpp"
struct MinMinMax
{
    int min1,min2,max;
};
MinMinMax CreateMinMinMax(int min1,int min2,int max)
{
    MinMinMax a;
    a.min1=min1;
    a.min2=min2;
    a.max=max;
    return a;
}
bool Compare(const MinMinMax &a,const MinMinMax &a2)
{
    return ((a.min1==a2.min1)&&(a.min2==a2.min2)&&(a.max==a2.max));
}
void Get2MinMax(std::vector<int>toSort,int &min1,int &min2,int &max)
{

//        while (_begin < _end)
//        {
//    int it=_begin;
    min1=10000000;
    min2=10000000;
    max=0;
    for (int it = 0; it <toSort.size(); it++)
    {
        if (toSort[it] < min1)
        {
            min2=min1;
            min1 = toSort[it];
        }
        else if(toSort[it]<min2 && min1!=min2 )
        {
            min2=toSort[it];
        }

        if (toSort[it] > max)
        {
            max = toSort[it];
        }

    }

}
void Get2Min(std::vector<int>toSort,int &first,int &second)
{

    VintIter _first = std::min_element(toSort.begin(),toSort.end());
    first=(*_first);
    toSort.erase(_first);
    VintIter _second = std::min_element(toSort.begin(),toSort.end());
    second=(*_second);
}
void Test()
{
    while(1)
    {
        system("cls");
        std::vector<int> v=Random::getInstance().generateRandomVector(1,10,10);
        for(int k : v)
        {
            std::cout<<k<<" ";
        }
        std::cout<<std::endl;


        int min1=0,min2=0,max=0;
        Get2MinMax(v,min1,min2,max);
        MinMinMax my=CreateMinMinMax(min1,min2,max);


        std::cout<<min1<<" "<<min2<<" "<<max<<std::endl;
        int min11=0,min12=0,max1=0;
        Get2Min(v,min11,min12);
        max1=*std::max_element(v.begin(),v.end());

        MinMinMax notMy=CreateMinMinMax(min11,min12,max1);
        bool compare = Compare(my,notMy);

        const char * ans = compare ? "the same" : "not the same";
        std::cout<<"MY: "<<my.min1<<" "<<my.min2<<" "<<my.max<<std::endl;
        std::cout<<"SYSTEM: "<<notMy.min1<<" "<<notMy.min2<<" "<<notMy.max<<std::endl;

        std::cout<<ans<<std::endl;


        assert(compare);
    }
}


#endif
