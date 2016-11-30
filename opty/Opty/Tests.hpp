#ifndef TESTS_H
#define TESTS_H
#include "typdefs.hpp"

class Tester
{
public :
    void addTest(const TestVisitor &_test, const AnyTest &_any)
    {
        m_testVector.push_back(_test);
        m_vectorOfTests.push_back(_any);
    }
    void performTests()
    {
        for(unsigned int i=0; i<m_testVector.size(); i++)
        {
            boost::apply_visitor(m_testVector[i],m_vectorOfTests[i]);
        }
    }
private:
    std::vector<TestVisitor> m_testVector;
    VectorOfTests m_vectorOfTests;
};


#endif
