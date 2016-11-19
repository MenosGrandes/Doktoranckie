
#include <iostream>
#include "../templatesSpecialisation.hpp"


int main(int argc, char* argv[] )
{
    srand((time(0)));
//
//        int i=9;
//        while(1)
//        {
//            std::vector<int>v;
//            v==Random::getInstance().generateRandomVector(1,10,3001);
//            std::sort(v.begin(),v.end(),std::greater<int>());
//            SortTripleBubble *stb= new SortTripleBubble(v);
//
//            system("cls");
//                        stb->print();
//
////             std::cout<<i<<std::endl;;
//            stb->_sort();
//            if(!stb->compare())
//            {
//                stb->print();
//
//                assert(stb->compare() && "Array wrongly sorted");
//
//            }
//
//            delete stb;
////            i+=111;
////            if(i>100000)
////            {
////                break;
////            }
//        }
    VectorOfTests tests;
    tests.push_back(TestBubbleSort() );
    tests.push_back(TestInsertSort() );
    tests.push_back(TestSelectionSort() );
    std::vector<std::string> namesOfTests{"TestBubbleSort","TestInsertSort","TestSelectionSort"};
                    boost::apply_visitor(TestVisitor(1,3001,9,WORST),tests[0]);

//#define DO_TESTS
#ifdef DO_TESTS
    VectorOfTests tests;
    tests.push_back(TestBubbleSort() );
    tests.push_back(TestInsertSort() );
    tests.push_back(TestSelectionSort() );
    std::vector<std::string> namesOfTests{"TestBubbleSort","TestInsertSort","TestSelectionSort"};
    std::vector<int>from{0,10000,40000,100000};
    std::vector<int>addition{500,1000,5000,10000};


    for(int _test=0; _test<1; _test++)
    {

        std::cout<<namesOfTests[_test]<<std::endl;
        for(int os=NON; os<LENGTH; os++)
        {
            int add=0;
            std::cout<<TEST_OPTIONS_TOSTRING((TEST_OPTIONS)os)<<std::endl;
            for(VintIter f=from.begin(); f!=(from.end()-1); f++,add++)
            {
                for(int i=(*f); i<*(f+1); i+=addition[add])
                {
                    std::cout<<i<<",";
                    boost::apply_visitor(TestVisitor(1,3001,100000,(TEST_OPTIONS)os),tests[_test]);
                }
            }
        }
    }



#endif // DO_TESTS

    return 0;
}
