
#include <iostream>
#include "../templatesSpecialisation.hpp"

#include "../Tests.hpp"

int main(int argc, char* argv[] )
{
    srand((time(0)));
//    int i=0;
////    while(1){
//
//
//            system("cls");
////            std::cout<<i<<" ";
//SortTripleBubble * sst= new SortTripleBubble(std::vector<int>{8,7,6,5,4,3,2,1,0});
//
////            Random::getInstance().generateRandomVector()
////sst->print();
//sst->_sort();
////sst->print();
//
//assert(sst->compare());
//SortTripleBubble * sst1= new SortTripleBubble(std::vector<int>{10,9,8,7,6,5,4,3,2,1,0});
//
////            Random::getInstance().generateRandomVector()
////sst->print();
//sst1->_sort();
////sst->print();
//
//assert(sst1->compare());
//SortTripleBubble * sst2= new SortTripleBubble(std::vector<int>{12,11,10,9,8,7,6,5,4,3,2,1,0});
//
////            Random::getInstance().generateRandomVector()
////sst->print();
//sst2->_sort();
////sst->print();
//
//assert(sst2->compare());
//
//
//
//SortTripleBubble * sst3= new SortTripleBubble(std::vector<int>{14,13,12,11,10,9,8,7,6,5,4,3,2,1,0});
//
////            Random::getInstance().generateRandomVector()
////sst->print();
//sst3->_sort();
////sst->print();
//
//assert(sst3->compare());
////i++;
////delete sst;
////}
//SortTripleBubble * sst4= new SortTripleBubble(std::vector<int>{16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0});
//
////            Random::getInstance().generateRandomVector()
////sst->print();
//sst4->_sort();
////sst->print();
//
//assert(sst4->compare());
////i++;
////delete sst;
////}
//
//SortTripleBubble * sst5= new SortTripleBubble(std::vector<int>{18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0});
//
////            Random::getInstance().generateRandomVector()
////sst->print();
//sst5->_sort();
////sst->print();
//
//assert(sst5->compare());
//
//SortTripleBubble * sst6= new SortTripleBubble(std::vector<int>{20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0});
//
////            Random::getInstance().generateRandomVector()
////sst->print();
//sst6->_sort();
////sst->print();
//
//assert(sst6->compare());
//SortTripleBubble * sst7= new SortTripleBubble(std::vector<int>{22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0});
//
////            Random::getInstance().generateRandomVector()
////sst->print();
//sst7->_sort();
////sst->print();
//
//assert(sst7->compare());
//SortTupleSelection * sts = new SortTupleSelection(9,10);
//sts->print();
//sts->_sort();
//sts->compare();
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
