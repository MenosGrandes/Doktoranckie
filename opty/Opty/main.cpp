// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***

#include <iostream>
#include "../templatesSpecialisation.hpp"

#include "../Tests.hpp"

#include "../conf/easylogging++.h"
void TEST_CASE()
{
         int x = 0;


    constexpr int vectorSize=1000;
    std::vector<int> n(vectorSize);
    std::generate(std::begin(n),std::end(n),[&]() { return x++; });
    TestHeapSort ths;
    TimeComprasions tc1 =ths.test(1,n,BEST);
    std::cout<<tc1.comprasions << " "<<tc1.time<<std::endl;
    std::generate(std::begin(n),std::end(n),[&]() { return x--; });
    TestHeapSort ths2;
    TimeComprasions tc2 =ths2.test(1,n,BEST);
    std::cout<<tc2.comprasions << " "<<tc2.time<<std::endl;
}
INITIALIZE_EASYLOGGINGPP
int main(int argc, char* argv[] )
{
    srand((time(0)));


    el::Loggers::configureFromGlobal("conf/logconf.conf");


//    int


    Tester tester;

    LOG(DEBUG)<<" ";

    std::vector<int> size1{100,1000,5000,20000,60000,110000};
    std::vector<int> appendSize{203,511,2031,8031,11020};


//    std::vector<int> size1{10,12};
//    std::vector<int> appendSize{1};
//    tester.createTests<TestBitonicSort>(5,size1,appendSize);
        tester.createTests<TestHeapSort>(5,size1,appendSize);
//    tester.createTests<TestMergeSort>(5,size1,appendSize);
//    tester.createTests<TestMergeSortOPTY>(5,size1,appendSize);

//    tester.createTests<TestShellSort>(5,size1,appendSize);
//    tester.createTests<TestQuickSort>(50,size1,appendSize,WORST);
//    tester.createTests<TestQuickSortOPTY>(50,size1,appendSize,WORST);

    tester.performTests();
Tester *t= new Tester();

    return 0;
}

