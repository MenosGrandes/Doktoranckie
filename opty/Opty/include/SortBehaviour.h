#ifndef SORTBEHAVIOUR_H
#define SORTBEHAVIOUR_H

#include "../typdefs.hpp"

class SortBehaviour
{
public :
    SortBehaviour() =default;
    virtual ~SortBehaviour()=default;
        SortBehaviour(SortBehaviour&& o)=default;
        SortBehaviour& operator=(const SortBehaviour& other)=default;
        SortBehaviour& operator=(SortBehaviour&& other)=default;
    virtual int sort(std::vector<int>&toSort)=0;
    static SortType m_sortType;
};

#endif // SORTBEHAVIOUR_H
