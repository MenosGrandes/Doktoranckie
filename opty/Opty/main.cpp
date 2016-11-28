
#include <iostream>
#include "../templatesSpecialisation.hpp"

#include "../Tests.hpp"

int main(int argc, char* argv[] )
{

    srand((time(0)));

    VectorOfTests tests;
    std::vector<int> toSort = Random::getInstance().generateRandomVector(1,10,pow(2,5));
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
        boost::apply_visitor(TestVisitor(1,toSort),tests[i]);

    }
    return 0;
}
