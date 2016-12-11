// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "WorstCaseMergeSort.h"
/*

Sort<BubbleSort,WorstCaseMergeSort,BestCase> a(std::vector<int>{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
 13, 14, 15, 16}});

    a.generateWorst();
a.print();
Should be:
{1, 9, 5, 13, 3, 11, 7, 15, 2, 10, 6,
 14, 4, 12, 8, 16}
*/

void WorstCaseMergeSort::generate(std::vector<int> &generator)
{
    //generateWorstCase(&generator[0], 0, generator.size() - 1);
    seperate(generator);
}


void WorstCaseMergeSort::merge(std::vector<int> &arr, std::vector<int> & left, std::vector<int> & right)
{
    int i,j;
    for(i=0; i<left.size(); i++)
        arr[i]=left[i];
    for(j=0; j<right.size(); j++,i++)
        arr[i]=right[j];
}

//Pass a sorted array here
void WorstCaseMergeSort::seperate(std::vector<int> &arr)
{

    if(arr.size()<=1)
        return;

    if(arr.size()==2)
    {
        int swap=arr[0];
        arr[0]=arr[1];
        arr[1]=swap;
        return;
    }

    int i,j;
    int m = (arr.size() + 1) / 2;


    std::vector<int> left(m) ;//= new int[m];
    std::vector<int> right(arr.size()-m);//= new int[arr.size()-m];

    for(i=0,j=0; i<arr.size(); i=i+2,j++) //Storing alternate elements in left subarray
        left[j]=arr[i];

    for(i=1,j=0; i<arr.size(); i=i+2,j++) //Storing alternate elements in right subarray
        right[j]=arr[i];

    seperate(left);
    seperate(right);
    merge(arr, left, right);
}
