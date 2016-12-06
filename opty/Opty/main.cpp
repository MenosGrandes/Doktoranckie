
#include <iostream>
#include "../templatesSpecialisation.hpp"

#include "../Tests.hpp"


int main(int argc, char* argv[] )
{


    el::Logger* businessLogger = el::Loggers::getLogger("business");
    el::Configurations conf("conf/logconf.conf");
    el::Loggers::reconfigureLogger("default", conf);
    // Actually reconfigure all loggers instead
    el::Loggers::reconfigureAllLoggers(conf);


    srand((time(0)));

    Tester tester;




    for(int option=0; option<LENGTH; option++)
    {
        for(int i=5; i<17; i++)
        {
            const int size = pow(2,i);

            tester.addTest(TestVisitor(10,size,static_cast<TEST_OPTIONS>(option)),TestBitonicSort());

        }
    }
    for(int option=0; option<LENGTH; option++)
    {
        for(int i=5; i<17; i++)
        {
            const int size = pow(2,i);

            tester.addTest(TestVisitor(10,size,static_cast<TEST_OPTIONS>(option)),TestHeapSort());

        }
    }
    for(int option=0; option<LENGTH; option++)
    {
        for(int i=5; i<17; i++)
        {
            const int size = pow(2,i);

            tester.addTest(TestVisitor(10,size,static_cast<TEST_OPTIONS>(option)),TestQuickSort());

        }
    }
    for(int option=0; option<LENGTH; option++)
    {
        for(int i=5; i<17; i++)
        {
            const int size = pow(2,i);

            tester.addTest(TestVisitor(10,size,static_cast<TEST_OPTIONS>(option)),TestShellSort());

        }
    }
    for(int option=0; option<LENGTH; option++)
    {
        for(int i=5; i<17; i++)
        {
            const int size = pow(2,i);

            tester.addTest(TestVisitor(10,size,static_cast<TEST_OPTIONS>(option)),TestMergeSort());

        }
    }


    tester.performTests();
    return 0;
}

