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

/*Tests*/
typedef TestSort<SortNormalBubble,SortTupleBubble,SortTripleBubble> TestBubbleSort;
typedef TestSort<SortNormalInsert,SortTupleInsert,SortTripleInsert> TestInsertSort;
typedef TestSort<SortNormalSelection,SortTupleSelection,SortTripleSelection> TestSelectionSort;
typedef TestSort<SortQuickSort> TestQuickSort;
typedef TestSort<SortMergeSort> TestMergeSort;
typedef TestSort<SortQuickSort,SortMergeSort,SortHeapSort> TestFastSort;
typedef boost::variant<TestBubbleSort,TestInsertSort,TestSelectionSort,TestQuickSort,TestMergeSort,TestFastSort>  AnyTest;
typedef std::vector<AnyTest>VectorOfTests;

class TestVisitor : public boost::static_visitor<>
{
public:
    template <typename T> void operator()( T & _t)const
    {
        _t.test(m_testCounts,m_tabSize,m_max,m_to);
    }
    TestVisitor(int _testCounts,int _tabSize,int _max,TEST_OPTIONS _so=NON):m_testCounts(_testCounts), m_tabSize(_tabSize), m_max(_max),m_to(_so) {}
private:
    int m_testCounts;
    int m_tabSize;
    int m_max;
    TEST_OPTIONS m_to;
};


#endif // TEMPLATES_SPECIALISATION_HPP
