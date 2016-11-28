#include "WorstCase.h"

WorstCase::WorstCase() {}
WorstCase::~WorstCase() {}
void WorstCase::generate(std::vector<int>& toSort)
{
    std::sort(toSort.begin(),toSort.end(), std::greater<int>());
}
