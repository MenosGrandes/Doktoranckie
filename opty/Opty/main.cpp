
#include <iostream>
#include "../templatesSpecialisation.hpp"

#include "../Tests.hpp"
int main(int argc, char* argv[] )
{

    srand((time(0)));
//std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
//WorstCaseHeapSort wchs;
//wchs.generate(v);
//for(int i: v)
//{
//    std::cout<< i<<" ";
//}
//std::vector<int> v2{1,2,3,4,5,6,7,8,9,10};
//BestCaseHeapSort wchs2;
//wchs2.generate(v2);
//for(int i: v2)
//{
//    std::cout<< i<<" ";
//}
Tester tester;
//tester.addTest(TestVisitor(1,100000,WORST),TestHeapSort());
//tester.addTest(TestVisitor(1,100000,BEST),TestHeapSort());
tester.addTest(TestVisitor(1,230,WORST),TestQuickSort());
//tester.addTest(TestVisitor(1,100000,WORST),TestQuickSort());
//tester.addTest(TestVisitor(10,10000,NON),TestNormalSelection());
//tester.addTest(TestVisitor(10,10000,NON),TestTupleSelection());
//tester.addTest(TestVisitor(1000,1000,NON),TestTripleSelection());

tester.performTests();
    return 0;
}
