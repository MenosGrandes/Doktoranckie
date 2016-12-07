
#include <iostream>
#include "../templatesSpecialisation.hpp"

#include "../Tests.hpp"


int main(int argc, char* argv[] )
{
    srand((time(0)));


    el::Configurations conf("conf/logconf.conf");
    el::Loggers::reconfigureLogger("default", conf);
    el::Loggers::reconfigureAllLoggers(conf);



    Tester tester;



    std::vector<int> size1{100,1000,5000,20000,60000,110000};
    std::vector<int> appendSize{203,511,2031,8031,11020};
    tester.createTests<TestBitonicSort>(1,size1,appendSize);
    tester.createTests<TestHeapSort>(1,size1,appendSize);
    tester.createTests<TestMergeSort>(1,size1,appendSize);
    tester.createTests<TestShellSort>(1,size1,appendSize);
    tester.createTests<TestQuickSort>(1,size1,appendSize);

    tester.performTests();
    return 0;
}

