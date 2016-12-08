#ifndef WORSTCASE_H
#define WORSTCASE_H

#include <vector>
#include <algorithm>
class WorstCase
{
public:
    WorstCase() =default;
    virtual ~WorstCase()=default;
    WorstCase(WorstCase&& o)=default;
    WorstCase& operator=(const WorstCase& other)=default;
    WorstCase& operator=(WorstCase&& other)=default;
    WorstCase(const WorstCase& a)=default;
    void generate(std::vector<int> &toSort) const
    {
        std::sort(toSort.begin(),toSort.end(), std::greater<int>());
    }
};

#endif // WORSTCASE_H
