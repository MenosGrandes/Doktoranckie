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


#include "WorstCaseHeapSort.h"
#include "WorstCaseMergeSort.h"


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
typedef Sort<HeapSort,WorstCaseHeapSort>  SortHeapSort;
typedef Sort<ShellSort>  SortShellSort;
typedef Sort<BitonicSort>  SortBitonicSort;

/*Tests*/
typedef TestSort<SortNormalBubble,SortTupleBubble,SortTripleBubble> TestBubbleSort;
typedef TestSort<SortNormalInsert,SortTupleInsert,SortTripleInsert> TestInsertSort;
typedef TestSort<SortNormalSelection,SortTupleSelection,SortTripleSelection> TestSelectionSort;

typedef TestSort<SortQuickSort> TestQuickSort;
typedef TestSort<SortMergeSort> TestMergeSort;
typedef TestSort<SortHeapSort> TestHeapSort;
typedef TestSort<SortShellSort> TestShellSort;
typedef TestSort<SortBitonicSort> TestBitonicSort;

typedef boost::variant<TestBubbleSort,TestInsertSort,TestSelectionSort,TestQuickSort,TestMergeSort,TestHeapSort,TestShellSort,TestBitonicSort>  AnyTest;
typedef std::vector<AnyTest>VectorOfTests;

class TestVisitor : public boost::static_visitor<>
{
public:
    template <typename T> void operator()( T & _t)const
    {
        _t.test(m_testCounts,m_toSort,m_to);
    }
    TestVisitor(int _testCounts,std::vector<int> _toSort,TEST_OPTIONS _so=NON):m_testCounts(_testCounts),m_to(_so),m_toSort(_toSort) {}
private:
    int m_testCounts;
    TEST_OPTIONS m_to;
    std::vector<int> m_toSort;
};


#endif // TEMPLATES_SPECIALISATION_HPP
