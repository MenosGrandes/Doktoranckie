// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***

#include <iostream>
#include "../templatesSpecialisation.hpp"

#include "../Tests.hpp"



int main(int argc, char* argv[] )
{
    srand((time(0)));


    el::Configurations conf("conf/logconf.conf");
    el::Loggers::reconfigureLogger("default", conf);
    el::Loggers::reconfigureAllLoggers(conf);

    std::vector<int> v{0,1,2,3,4,5,6,7};


    Tester tester;

    LOG(DEBUG)<<" ";

//    std::vector<int> size1{100,1000,5000,20000,60000,110000};
//    std::vector<int> appendSize{203,511,2031,8031,11020};


    std::vector<int> size1{10,12};
    std::vector<int> appendSize{1};
    tester.createTests<TestBitonicSort>(5,size1,appendSize);
    tester.createTests<TestHeapSort>(5,size1,appendSize);
    tester.createTests<TestMergeSort>(5,size1,appendSize);
//    tester.createTests<TestMergeSortOPTY>(5,size1,appendSize);

//    tester.createTests<TestShellSort>(5,size1,appendSize);
//    tester.createTests<TestQuickSort>(50,size1,appendSize,WORST);
//    tester.createTests<TestQuickSortOPTY>(50,size1,appendSize,WORST);

    tester.performTests();


    return 0;
}

