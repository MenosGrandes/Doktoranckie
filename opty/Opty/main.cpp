
#include <iostream>
#include "../templatesSpecialisation.hpp"

#include "../Tests.hpp"
int main(int argc, char* argv[] )
{

    srand((time(0)));

Tester tester;
//tester.addTest(TestVisitor(10,10000,NON),TestNormalSelection());
//tester.addTest(TestVisitor(10,10000,NON),TestTupleSelection());
tester.addTest(TestVisitor(1000,1000,NON),TestTripleSelection());

tester.performTests();
    return 0;
}
