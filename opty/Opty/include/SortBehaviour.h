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
    virtual uint256_t sort(std::vector<int>&toSort)=0;
    static SortType m_sortType;
protected:
        uint256_t compareCounter;

};

#endif // SORTBEHAVIOUR_H
