#ifndef SORTSELECTIONTUPLE_H
#define SORTSELECTIONTUPLE_H


#include "../typdefs.hpp"
#include <algorithm>
class SortSelectionTuple
{
public:
      SortSelectionTuple(){};
    ~SortSelectionTuple(){};
    void sort(std::vector<int> &toSort)
    {
        VintIter _begin = toSort.begin();
        VintIter _end   = (toSort.end()-1);
        for( int i=0; i<toSort.size()/2; i++,_begin++,_end--)
        {
            const std::pair<const VintIter,const VintIter> _minmax=std::minmax_element(_begin,_end+1);

            if(_minmax.first == _end && _minmax.second == _begin)
            {
                std::iter_swap(_begin,_end);
            }
            else
            {
                if(_minmax.first == _end)
                {
                    std::iter_swap(_begin,_minmax.first);
                    std::iter_swap(_end,_minmax.second);
                }
                else
                {
                    std::iter_swap(_end,_minmax.second);
                    std::iter_swap(_begin,_minmax.first);
                }
            }

        }

    }


};

#endif // SORTSELECTIONTUPLE_H
