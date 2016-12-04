#ifndef WORSTCASE_H
#define WORSTCASE_H

#include "../typdefs.hpp"

class WorstCase
{
public:
    WorstCase();
    virtual ~WorstCase();
    void generate(std::vector<int> &toSort) const;
};

#endif // WORSTCASE_H
