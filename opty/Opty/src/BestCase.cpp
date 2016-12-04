#include "BestCase.h"

BestCase::BestCase() {}
BestCase::~BestCase() {}
void BestCase::generate(std::vector<int>& toSort) const
{
    std::sort(toSort.begin(),toSort.end(), std::less<int>());
}
