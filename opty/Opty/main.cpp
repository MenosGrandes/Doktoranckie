
#include <iostream>
#include "../templatesSpecialisation.hpp"

#include "../Tests.hpp"

int main(int argc, char* argv[] )
{
    srand((time(0)));

    SortQuickSort *qs = new SortQuickSort(100000,100);
    qs->_sort();
    assert(qs->compare());
//    qs->print();
    //    std::vector<int> a = {11,10,9,8,7,6,5,4,3,2,1};//Random::getInstance().generateRandomVector(1,100,1000);
//    std::vector<int> b= a;
//    std::vector<int> c= a;
//    SortTripleInsert * sti1 = new SortTripleInsert(c);
//
//    sti1->_sort();
//
    delete qs;


#define DO_TESTS
#ifdef DO_TESTS
    VectorOfTests tests;
//    tests.push_back(TestBubbleSort() );
//    tests.push_back(TestInsertSort() );
    tests.push_back(TestSelectionSort() );
    std::vector<std::string> namesOfTests{"TestSelectionSort"};
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
                    boost::apply_visitor(TestVisitor(1,i,100000,(TEST_OPTIONS)os),tests[_test]);
                }
            }
        }
    }



#endif // DO_TESTS

    return 0;
}
