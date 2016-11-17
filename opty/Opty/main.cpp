
#include "TestSort.h"
#include "Tests.hpp"


#include "BubbleSort.h"
#include "SortInsert.h"
#include "SortSelection.h"

#include "SortSelectionTuple.h"
#include "SortBubbleTuple.h"
#include "SortInsertTuple.h"

#include "SortSelectionTriple.h"
#include "SortInsertTriple.h"
#include "SortBubbleTriple.h"

#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
/*NORMAL*/
typedef Sort<BubbleSort> SortNormalBubble;
typedef Sort<SortInsert> SortNormalInsert;
typedef Sort<SortSelection> SortNormalSelection;

/*TUPLES*/
typedef Sort<SortSelectionTuple> SortTupleSelection;
typedef Sort<SortBubbleTuple> SortTupleBubble;
typedef Sort<SortInsertTuple> SortTupleInsert;
/*TRIPLES*/
typedef Sort<SortInsertTriple> SortTripleInsert;
typedef Sort<SortBubbleTriple> SortTripleBubble;
typedef Sort<SortSelectionTriple> SortTripleSelection;

/*Tests*/
typedef TestSort<SortNormalBubble,SortTupleBubble,SortTripleBubble> TestBubbleSort;
typedef TestSort<SortNormalInsert,SortTupleInsert,SortTripleInsert> TestInsertSort;
typedef TestSort<SortNormalSelection,SortTupleSelection,SortTripleSelection> TestSelectionSort;





int main(int argc, char* argv[] )
{
    srand((time(0)));
    /*
    bool saveToFile = false;
    int testCountes = 0;
    int vectorSize = 0;
    int minimum = 0;
    int maximum =100;
    std::string fileName;
    SORTING_OPTIONS _reference=NORMAL_BUBBLE,_test=TUPLE_BUBBLE;

         const char* nvalue = "World" ;
        int tvalue = 1 ;

        int c ;
        while( ( c = getopt (argc, argv, "n:t:m:x:y:a:b:f:") ) != -1 )
        {
            switch(c)
            {
                case 'f':
                    if(optarg){ saveToFile=true; fileName=optarg;};
                    break;
                case 'n':
                    if(optarg) {testCountes = std::atoi(optarg); };
                    break;
                case 'm':
                    if(optarg) {vectorSize = std::atoi(optarg); };
                    break;
                case 'x':
                    if(optarg) {minimum = std::atoi(optarg); };
                    break;
                case 'y':
                    if(optarg) {maximum = std::atoi(optarg); };
                    break;
                case 'a':
                    if(optarg) {_reference = (SORTING_OPTIONS)std::atoi(optarg); };
                    break;
                case 'b':
                    if(optarg) {_test = (SORTING_OPTIONS)std::atoi(optarg); };
                    break;
                case '?':
                    std::cout<<"Usage :"<<std::endl<<"\t -f <fileName>. Save to <fileName>.txt"<<std::endl;
                    std::cout<<"\t -n <count>. Test <count> times"<<std::endl;
                    std::cout<<"\t -m <count>. Create vector of <count> length"<<std::endl;
                    std::cout<<"\t -x <count>. Generete random numbers from <count>"<<std::endl;
                    std::cout<<"\t -y <count>. Generete random numbers to <count>"<<std::endl;
                    std::cout<<"\t -a <name>. Crete <test>(Sort class) as reference to <test>b .Pass number from 0 to 5"<<std::endl;
                    std::cout<<"\t -b <name>. Crete <test>(Sort class) to test with b(Sort class) .Pass number from 0 to 5"<<std::endl;

                    break;
            }
        }

    std::ofstream testFile;
    if(saveToFile)
    {
        testFile.open(fileName);
    }
    std::cout<<"Test "<<SortingOptionsToString(_reference)<<" with "<<SortingOptionsToString(_test)<<" "<<testCountes<<" times. Where vector will have "<<vectorSize<<" elements, with numbers from "<<minimum<<" to "<<maximum<<std::endl;
    */
//while(1){
////        system("cls");
//SortTripleBubble *stb  = new SortTripleBubble(100000,10000);
////stb->print();
//stb->_sort();
////stb->print();
//if(stb->compare()==false)
//{
//    stb->print();
//    assert(false);
//}
//std::cout<<"DONE"<<std::endl;
//delete stb;
//}
#define DO_TESTS
#ifdef DO_TESTS
    TestBubbleSort tbs;
    TestInsertSort tis;
    TestSelectionSort tss;
    std::vector<int>from{0,10000,40000,100000};
    std::vector<int>addition{500,1000,5000,10000};

     tbs.test(1,1000,100000);


//    for(int os=NON; os<LENGTH; os++)
//    {
//        int add=0;
//        std::cout<<TEST_OPTIONS_TOSTRING((TEST_OPTIONS)os)<<std::endl;
//        for(VintIter f=from.begin(); f!=(from.end()-1); f++)
//        {
//            std::cout<<"TestBubbleSort"<<std::endl;
//            for(int i=(*f); i<*(f+1); i+=addition[add])
//            {
//                std::cout<<i<<",";
//                tbs.test(1,i,100000,(TEST_OPTIONS)os);
//            }
//            add++;
//        }
//    }
//
//    for(int os=NON; os<LENGTH; os++)
//    {
//        int add=0;
//        std::cout<<TEST_OPTIONS_TOSTRING((TEST_OPTIONS)os)<<std::endl;
//        for(VintIter f=from.begin(); f!=(from.end()-1); f++)
//        {
//            std::cout<<"TestInsertSort"<<std::endl;
//            for(int i=(*f); i<*(f+1); i+=addition[add])
//            {
//                std::cout<<i<<",";
//                tis.test(1,i,100000,(TEST_OPTIONS)os);
//            }
//            add++;
//        }
//    }
//
//    for(int os=NON; os<LENGTH; os++)
//    {
//        int add=0;
//        std::cout<<TEST_OPTIONS_TOSTRING((TEST_OPTIONS)os)<<std::endl;
//        for(VintIter f=from.begin(); f!=(from.end()-1); f++)
//        {
//            std::cout<<"TestSelectionSort"<<std::endl;
//            for(int i=(*f); i<*(f+1); i+=addition[add])
//            {
//                std::cout<<i<<",";
//                tss.test(1,i,100000,(TEST_OPTIONS)os);
//            }
//            add++;
//        }
//    }


#endif // DO_TESTS

    return 0;
}
