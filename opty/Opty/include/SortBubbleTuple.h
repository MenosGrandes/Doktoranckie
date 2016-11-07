#ifndef SORTBUBBLETUPLE_H
#define SORTBUBBLETUPLE_H
#include "../typdefs.hpp"
class SortBubbleTuple
{
public:

    SortBubbleTuple(){};
    ~SortBubbleTuple(){};
    void sort(std::vector<int> &toSort)
    {
        const int sortSize=toSort.size();
        for (int i = 0; i < (sortSize)/2; ++i)
        {
            bool change = false;
            for (int j = i; j < sortSize - i - 1; j++)   //one way
            {
                if (toSort[j] > toSort[j+1])
                {
                    const int tmp = toSort[j];
                    toSort[j] = toSort[j+1];
                    toSort[j+1] = tmp;
                    change = true;
                }
            }
            for (int j = sortSize - 2 - i; j > i; j--)   //and back
            {
                if (toSort[j] < toSort[j-1])
                {
                    const int tmp = toSort[j];
                    toSort[j] = toSort[j-1];
                    toSort[j-1] = tmp;
                    change = true;
                }
            }
            if(!change)
            {
                break;    //block (break if no element was swapped - the m_data is sorted)
            }

        }
    }

};

#endif // SORTBUBBLETUPLE_H
