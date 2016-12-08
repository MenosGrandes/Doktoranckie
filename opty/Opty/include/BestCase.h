#ifndef BESTCASE_H
#define BESTCASE_H

#include <vector>
#include <algorithm>
class BestCase
{
public:

    BestCase() =default;
    virtual ~BestCase()=default;
    BestCase(BestCase&& o)=default;
    BestCase& operator=(const BestCase& other)=default;
    BestCase& operator=(BestCase&& other)=default;
    BestCase(const BestCase& a)=default;
    void generate(std::vector<int> &toSort) const
    {
        std::sort(toSort.begin(),toSort.end(), std::less<int>());
    }
};

#endif // BESTCASE_H
