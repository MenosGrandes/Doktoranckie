#ifndef SORT_H
#define SORT_H

#include <algorithm>
#include <functional>
#include <vector>
#include "BubbleSort.h"
#include "SortInsert.h"
#include "SortSelection.h"
#include "SortSelectionTuple.h"
#include "SortBubbleTuple.h"
#include "SortInsertTuple.h"
#include "Random.h"

template <class SortMethod>
class Sort
{
public:
    Sort(int n, int max);
    Sort(std::vector<int> append);

    virtual ~Sort();
    void print() const;
    void _sort();
    bool compare();
protected:
    std::vector<int> m_data;
    std::vector<int> compareData;
    int m_n;
    void _swap(int x,int y);
private:
    Sort(const Sort &a):m_data(a.m_data),compareData(a.compareData),m_n(a.m_n) {};
    Sort(Sort&& o):m_data(std::move(o.m_data)),compareData(std::move(o.compareData)),m_n(std::move(m_n)){ }
    SortMethod* sortMethod;
};
/*NORMAL*/
template class Sort<BubbleSort>;
typedef Sort<BubbleSort> SortNormalBubble;

template class Sort<SortInsert>;
typedef Sort<SortInsert> SortNormalInsert;

template class Sort<SortSelection>;
typedef Sort<SortSelection> SortNormalSelection;

/*TUPLES*/
template class Sort<SortSelectionTuple>;
typedef Sort<SortSelectionTuple> SortTupleSelection;

template class Sort<SortBubbleTuple>;
typedef Sort<SortBubbleTuple> SortTupleBubble;

template class Sort<SortInsertTuple>;
typedef Sort<SortInsertTuple> SortTupleInsert;





#endif // SORT_H
