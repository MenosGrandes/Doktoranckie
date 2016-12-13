// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***

#include <iostream>
#include "../templatesSpecialisation.hpp"

#include "../Tests.hpp"

#include "../conf/easylogging++.h"
void TEST_CASE_HEAP()
{
    int x = 0;


    constexpr int vectorSize=1000;
    std::vector<int> n(vectorSize);
    std::generate(std::begin(n),std::end(n),[&]()
    {
        return x++;
    });
    TestHeapSort ths;
    TimeComprasions tc1 =ths.test(1,n);
    std::cout<<tc1.comprasions << " "<<tc1.time<<std::endl;
    std::generate(std::begin(n),std::end(n),[&]()
    {
        return x--;
    });
    TestHeapSort ths2;
    TimeComprasions tc2 =ths2.test(1,n);
    std::cout<<tc2.comprasions << " "<<tc2.time<<std::endl;
//    n = Random::getInstance().generateRandomVector(1,1000,n.size());
        std::generate(std::begin(n),std::end(n),[&]()
    {
        return Random::getInstance().generate(1,10000);
    });
    TestHeapSort ths3;
    TimeComprasions tc3 =ths3.test(1,n);
    std::cout<<tc3.comprasions << " "<<tc3.time<<std::endl;
}
void TEST_CASE_BITONIC()
{
        int x = 0;

        constexpr int vectorSize=1000;
    std::vector<int> n(vectorSize);
    std::generate(std::begin(n),std::end(n),[&]()
    {
        return x++;
    });
    TestBitonicSort ths;
    TimeComprasions tc1 =ths.test(1,n);
    std::cout<<tc1.comprasions << " "<<tc1.time<<std::endl;
    std::generate(std::begin(n),std::end(n),[&]()
    {
        return x--;
    });
    TestBitonicSort ths2;
    TimeComprasions tc2 =ths2.test(1,n);
    std::cout<<tc2.comprasions << " "<<tc2.time<<std::endl;
}

INITIALIZE_EASYLOGGINGPP
int main(int argc, char* argv[] )
{
    srand((time(0)));


    el::Loggers::configureFromGlobal("conf/logconf.conf");


    Tester tester;

    LOG(DEBUG)<<" ";

    std::vector<int> size1{100,1000,5000,20000,60000,110000};
    std::vector<int> appendSize{203,511,2031,8031,11023};


//    tester.createTests<TestBitonicSort>(5,size1,appendSize);
//    tester.createTests<TestHeapSort>(5,size1,appendSize);
//    tester.createTests<TestMergeSort>(5,size1,appendSize);
//    tester.createTests<TestShellSort>(5,size1,appendSize);
    tester.createTests<TestQuickSort>(20,size1,appendSize);
    tester.createTests<TestQuickSortOPTY>(20,size1,appendSize);
//
    tester.performTests();

//TEST_CASE_HEAP();
    return 0;
}

