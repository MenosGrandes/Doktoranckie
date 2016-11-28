
#include <iostream>
#include "../templatesSpecialisation.hpp"

#include "../Tests.hpp"
#include "WorstCaseMergeSort.h"
int main(int argc, char* argv[] )
{
//WorstCaseMergeSort w_Merge;
//std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9,
//                 10, 11, 12, 13, 14, 15, 16 };
//std::vector<int> g =w_Merge.generate(v);
//for(int i : g)
//{
//    std::cout<<i<<" ";
//}
//std::cout<<std::endl;
    srand((time(0)));



    VectorOfTests tests;
    std::vector<int> toSort = Random::getInstance().generateRandomVector(1,10000000,pow(2,10));
    tests.push_back(TestInsertSort());
    tests.push_back(TestBubbleSort());
    tests.push_back(TestQuickSort());
    tests.push_back(TestQuickSort());
    tests.push_back(TestMergeSort());
    tests.push_back(TestHeapSort());
    tests.push_back(TestShellSort());
    tests.push_back(TestQuickSort());
    tests.push_back(TestBitonicSort());
    for(unsigned int i=0; i<tests.size(); i++)
    {
        boost::apply_visitor(TestVisitor(1,toSort,WORST),tests[i]);

    }
    return 0;
}
