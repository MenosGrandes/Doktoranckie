#ifndef BESTCASE_H
#define BESTCASE_H

#include "../typdefs.hpp"
class BestCase
{
public:
    BestCase();
    virtual ~BestCase();
    void generate(std::vector<int> &toSort);
};

#endif // BESTCASE_H
