#ifndef SORTBEHAVIOUR_H
#define SORTBEHAVIOUR_H

#include "../typdefs.hpp"
class SortBehaviour
{
public :
    SortBehaviour(){};
    virtual ~SortBehaviour(){};
    virtual void sort(std::vector<int>&toSort)=0;
    static SortType m_sortType;


};

#endif // SORTBEHAVIOUR_H
