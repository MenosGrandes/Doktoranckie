#include "SortSelection.h"

SortSelection::SortSelection(int n, int max):Sort(n,max){}
SortSelection::~SortSelection(){}

void SortSelection::_sort()
{
    std::cout<<"!!@!@!@!@!@!@"<<std::endl;
    for(VintIter it = m_data.begin(); it != m_data.end()-1; ++it)
    {
        VintIter next=(it);
        std::iter_swap((std::min_element(next++,m_data.end())),it);
    }
}
