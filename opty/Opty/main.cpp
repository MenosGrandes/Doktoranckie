
#include <iostream>
#include "../templatesSpecialisation.hpp"

#include "../Tests.hpp"

int main(int argc, char* argv[] )
{
    srand((time(0)));
//    while(1){


            system("cls");
SortTripleBubble * sst= new SortTripleBubble(std::vector<int>{8,7,6,5,4,3,2,1});

//            Random::getInstance().generateRandomVector()
//sst->print();
sst->_sort();
//sst->print();

sst->compare();
delete sst;
//}
#ifdef DO_TESTS
    VectorOfTests tests;
    tests.push_back(TestBubbleSort() );
//    tests.push_back(TestInsertSort() );
//    tests.push_back(TestSelectionSort() );
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
