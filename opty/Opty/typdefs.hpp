
#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <vector>
#include <iostream>
#include <string>


#define MAX_INT 100000000
typedef std::vector<int>::iterator VintIter;
typedef std::pair<VintIter,VintIter> VintIterPair;
std::string CompareBool(VintIter b1,VintIter b2)
{
    if(b1==b2)
    {
        return "true";
    }
    else
    {
        return "false";
    }

}
//
//

#endif // TYPEDEFS
