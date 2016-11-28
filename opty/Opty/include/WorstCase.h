#ifndef WORSTCASE_H
#define WORSTCASE_H

#include "../typdefs.hpp"

class WorstCase
{
public:
    WorstCase();
    virtual ~WorstCase();
    void generate(std::vector<int> &toSort);
};

#endif // WORSTCASE_H
