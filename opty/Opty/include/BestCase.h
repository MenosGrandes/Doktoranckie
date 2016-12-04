#ifndef BESTCASE_H
#define BESTCASE_H

#include "../typdefs.hpp"
class BestCase
{
public:
    BestCase();
    virtual ~BestCase();
    void generate(std::vector<int> &toSort) const;
};

#endif // BESTCASE_H
