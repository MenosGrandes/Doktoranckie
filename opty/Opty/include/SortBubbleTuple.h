#ifndef SORTBUBBLETUPLE_H
#define SORTBUBBLETUPLE_H
#include "../typdefs.hpp"

/*
http://www.dreamincode.net/forums/topic/122481-finding-the-two-lowest-values-in-array/
*/
class SortBubbleTuple
{
public:

    SortBubbleTuple(){};
    ~SortBubbleTuple(){};
    void sort(std::vector<int> &toSort)
    {
//        const int sortSize=toSort.size();
//        for (int i = 0; i < (sortSize)/2; ++i)
//        {
//            bool change = false;
//            for (int j = i; j < sortSize - i - 1; j++)   //one way
//            {
//                if (toSort[j] > toSort[j+1])
//                {
//                    const int tmp = toSort[j];
//                    toSort[j] = toSort[j+1];
//                    toSort[j+1] = tmp;
//                    change = true;
//                }
//            }
//            for (int j = sortSize - 2 - i; j > i; j--)   //and back
//            {
//                if (toSort[j] < toSort[j-1])
//                {
//                    const int tmp = toSort[j];
//                    toSort[j] = toSort[j-1];
//                    toSort[j-1] = tmp;
//                    change = true;
//                }
//            }
//            if(!change)
//            {
//                break;    //block (break if no element was swapped - the m_data is sorted)
//            }
//
//        }


for(int i = 0; i < toSort.size(); i++)
{
	int j = toSort.size();
	while(j-- >= i)
	{
		if(toSort[j] > toSort[j + 1])
		{
            std::swap(toSort[j],toSort[j+1]);
            std::swap(toSort[j+1],toSort[j]);
            std::swap(toSort[j],toSort[j+1]);

		}
	}
}

//std::cout << "Smallest elem " << toSort[0] << " next smallest elem " << toSort[1] << "\n";



    }

};

#endif // SORTBUBBLETUPLE_H
