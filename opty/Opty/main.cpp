
#include <iostream>
#include "../templatesSpecialisation.hpp"


int main(int argc, char* argv[] )
{
    srand((time(0)));
//    while(1){
//            system("cls");
//SortTupleSelection * sst= new SortTupleSelection(1000,9);
//sst->print();
//sst->_sort();
//sst->print();
//delete sst;
//}

#define DO_TESTS
#ifdef DO_TESTS
    VectorOfTests tests;
//    tests.push_back(TestBubbleSort() );
//    tests.push_back(TestInsertSort() );
    tests.push_back(TestSelectionSort() );
    std::vector<std::string> namesOfTests{"TestBubbleSort","TestInsertSort","TestSelectionSort"};
    std::vector<int>from{0,10000,40000,100000};
    std::vector<int>addition{500,1000,5000,10000};


    for(int _test=0; _test<tests.size(); _test++)
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
                    boost::apply_visitor(TestVisitor(1,i,100000),tests[_test]);
                }
            }
        }
    }



#endif // DO_TESTS

    return 0;
}
