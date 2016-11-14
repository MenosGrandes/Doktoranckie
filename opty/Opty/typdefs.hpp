
#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <vector>
#include <iostream>
#include <string>

enum SORTING_OPTIONS
{
    NORMAL_BUBBLE,NORMAL_INSERT,NORMAL_SELECTION,
    TUPLE_BUBBLE,TUPLE_INSERT,TUPLE_SELECTION,
    TRIPLE_BUBBLE,TRIPLE_INSERT,TRIPLE_SELECTION

};
enum TEST_OPTIONS
{
    NON,BEST,WORST,LENGTH
};



typedef std::vector<int>::iterator VintIter;
typedef std::pair<VintIter,VintIter> VintIterPair;
std::string CompareBool(VintIter b1,VintIter b2)
{
    if(b1==b2)
    {
        return "true";
    }
    else
    {
        return "false";
    }

}
std::string TEST_OPTIONS_TOSTRING(TEST_OPTIONS s)
{
    switch(s)
    {
    case NON:
        return "NormalBubbleSort";
        break;
    case BEST:
        return "NormalBubbleSort";
        break;
    case WORST:
        return "NormalBubbleSort";
        break;
    case LENGTH:
        return "NormalBubbleSort";
        break;
    }
    return "";
}

std::string SortingOptionsToString(SORTING_OPTIONS s)
{
    switch(s)
    {
    case NORMAL_BUBBLE:
        return "NormalBubbleSort";
        break;
    case NORMAL_INSERT:
        return "NormalInsertSort";
        break;
    case NORMAL_SELECTION:
        return "NormalSelectionSort";
        break;
    case TUPLE_BUBBLE:
        return "TupleBubbleSort";
        break;
    case TUPLE_INSERT:
        return "TupleInsertSort";
        break;
    case TUPLE_SELECTION:
        return "TupleSelectionSort";
        break;
    case TRIPLE_BUBBLE:
        return "TripleBubbleSort";
        break;
    case TRIPLE_INSERT:
        return "TripleInsertSort";
        break;
    case TRIPLE_SELECTION:
        return "TripleSelectionSort";
        break;

    }
    return "";
}
//
//

#endif // TYPEDEFS
