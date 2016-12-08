#ifndef TESTS_H
#define TESTS_H
#include "typdefs.hpp"

class Tester
{
public :
    Tester() = default;
    ~Tester() = default;
    void addTest(const TestVisitor &_test, const AnyTest &_any)
    {
        m_testVector.push_back(_test);
        m_vectorOfTests.push_back(_any);
    }
    template<class Test>
    void createTests(int testCounts,const std::vector<int> &size1,const std::vector<int> &appendSize)
    {
        for(int option=0; option<LENGTH; option++)
        {
            int counter=0;
            for(std::vector<int>::const_iterator i = std::begin(size1); i!=std::end(size1)-1; ++i)
            {
                int size = *i;
                while(size<*(i+1))
                {
                    addTest(TestVisitor(testCounts,size,static_cast<TEST_OPTIONS>(option)),Test());
                    size+=appendSize[counter];
                }
                counter++;
            }
        }
    }
    template<class Test>
    void createTests(int testCounts,const std::vector<int> &size1,const std::vector<int> &appendSize,TEST_OPTIONS option)
    {

        int counter=0;
        for(std::vector<int>::const_iterator i = std::begin(size1); i!=std::end(size1)-1; ++i)
        {
            int size = *i;
            while(size<*(i+1))
            {
                addTest(TestVisitor(testCounts,size,option),Test());
                size+=appendSize[counter];
            }
            counter++;
        }
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
