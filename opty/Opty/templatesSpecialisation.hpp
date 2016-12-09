
#ifndef TEMPLATES_SPECIALISATION_HPP
#define TEMPLATES_SPECIALISATION_HPP

#include "TestSort.h"

#include "BubbleSort.h"
#include "SortInsert.h"
#include "SortSelection.h"

#include "SortSelectionTuple.h"
#include "SortBubbleTuple.h"
#include "SortInsertTuple.h"

#include "SortSelectionTriple.h"
#include "SortInsertTriple.h"
#include "SortBubbleTriple.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "ShellSort.h"
#include "BitonicSort.h"
#include "QuickSortOPTY.h"
#include "MergeSortOPTY.h"

#include "WorstCaseHeapSort.h"
#include "WorstCaseMergeSort.h"
#include "BestCaseHeapSort.h"

#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/variant/variant.hpp>
#include <boost/variant/get.hpp>
#include<tuple>
#include <typeinfo>
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
/*FAST*/
typedef Sort<QuickSort> SortQuickSort;
typedef Sort<MergeSort> SortMergeSort;
typedef Sort<HeapSort>  SortHeapSort;
typedef Sort<ShellSort>  SortShellSort;
typedef Sort<BitonicSort>  SortBitonicSort;
/*Optimised*/
typedef Sort<QuickSortOPTY> SortQuickSortOPTY;
typedef Sort<MergeSortOPTY> SortMergeSortOPTY;

/*Tests*/
typedef TestSort<SortNormalBubble> TestNormalBubble;
typedef TestSort<SortNormalInsert>TestNormalInsert;
typedef TestSort<SortNormalSelection>TestNormalSelection;
typedef TestSort<SortTupleSelection>TestTupleSelection;
typedef TestSort<SortTupleBubble>TestTupleBubble;
typedef TestSort<SortTupleInsert>TestTupleInsert;
typedef TestSort<SortTripleInsert>TestTripleInsert;
typedef TestSort<SortTripleBubble>TestTripleBubble;
typedef TestSort<SortTripleSelection>TestTripleSelection;

typedef TestSort<SortQuickSort,BestCase,WorstCase> TestQuickSort;

typedef TestSort<SortMergeSort,WorstCaseMergeSort,BestCase> TestMergeSort;
typedef TestSort<SortHeapSort,WorstCaseHeapSort,BestCase> TestHeapSort;
typedef TestSort<SortShellSort> TestShellSort;
typedef TestSort<SortBitonicSort> TestBitonicSort;


typedef TestSort<SortQuickSortOPTY,BestCase,WorstCase> TestQuickSortOPTY;
typedef TestSort<SortMergeSortOPTY,WorstCaseMergeSort,BestCase> TestMergeSortOPTY;

typedef boost::variant<
TestNormalBubble,TestNormalInsert,TestNormalSelection,
                 TestTupleSelection,TestTupleBubble,TestTupleInsert,
                 TestTripleInsert,TestTripleBubble,TestTripleSelection,
                 TestQuickSort,TestMergeSort,TestHeapSort,TestShellSort,TestBitonicSort,
                 TestQuickSortOPTY,TestMergeSortOPTY
                 >  AnyTest;

typedef std::vector<AnyTest>VectorOfTests;


class TestVisitor : public boost::static_visitor<>
{
public:
            TestVisitor() =default;
       ~TestVisitor()=default;
        TestVisitor(TestVisitor&& o)=default;
        TestVisitor& operator=(const TestVisitor& other)=default;
        TestVisitor& operator=(TestVisitor&& other)=default;
        TestVisitor(const TestVisitor& a)=default;
    template <typename T> void operator()( T & _t)const
    {
        const TimeComprasions tc= _t.test(m_testCounts,m_sortSizeVector,m_to);

        LOG(INFO)<<_t.getType()<<","<<ToString(m_to)<<","<<m_sortSizeVector<<","<<tc.time<<","<<tc.comprasions;
    }
    TestVisitor(int _testCounts,int _sortSizeVector,TEST_OPTIONS _so):m_testCounts(_testCounts),m_to(_so),m_sortSizeVector(_sortSizeVector) {}
private:
    int m_testCounts;
    TEST_OPTIONS m_to;
    int m_sortSizeVector;
};


#endif // TEMPLATES_SPECIALISATION_HPP
