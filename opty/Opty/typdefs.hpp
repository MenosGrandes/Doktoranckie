
#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <vector>
#include <iostream>
<<<<<<< HEAD
#include <string>


#define MAX_INT 100000000
=======




>>>>>>> 6c2106290186e1a32c35f96edfbd6e5d738b32c5
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
