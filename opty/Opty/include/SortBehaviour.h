#ifndef SORTBEHAVIOUR_H
#define SORTBEHAVIOUR_H

#include "../typdefs.hpp"

class SortBehaviour
{
public :
    SortBehaviour() {};
    virtual ~SortBehaviour() {};
    int sort(std::vector<int>&toSort){};
    static SortType m_sortType;
};

#endif // SORTBEHAVIOUR_H
