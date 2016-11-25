
#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <vector>
#include <iostream>
#include <string>
#include <boost/assert.hpp>
#include <boost/preprocessor.hpp>

#define X_DEFINE_ENUM_WITH_STRING_CONVERSIONS_TOSTRING_CASE(r, data, elem)    \
    case elem : return BOOST_PP_STRINGIZE(elem);

#define DEFINE_ENUM_WITH_STRING_CONVERSIONS(name, enumerators)                \
    enum name {                                                               \
        BOOST_PP_SEQ_ENUM(enumerators)                                        \
    };                                                                        \
                                                                              \
    inline const char* ToString(name v)                                       \
    {                                                                         \
        switch (v)                                                            \
        {                                                                     \
            BOOST_PP_SEQ_FOR_EACH(                                            \
                X_DEFINE_ENUM_WITH_STRING_CONVERSIONS_TOSTRING_CASE,          \
                name,                                                         \
                enumerators                                                   \
            )                                                                 \
            default: return "[Unknown " BOOST_PP_STRINGIZE(name) "]";         \
        }                                                                     \
    }


DEFINE_ENUM_WITH_STRING_CONVERSIONS(SortType,
                                    (NORMAL_BUBBLE)(NORMAL_INSERT)(NORMAL_SELECTION)
                                    (TUPLE_BUBBLE)(TUPLE_INSERT)(TUPLE_SELECTION)
                                    (TRIPLE_BUBBLE)(TRIPLE_INSERT)(TRIPLE_SELECTION)
                                    (QUICK)(MERGE)(SHELL)(HEAP)(BITONIC)
                                   )

enum TEST_OPTIONS
{
    NON,BEST,WORST,LENGTH
};


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
std::string TEST_OPTIONS_TOSTRING(TEST_OPTIONS s)
{
    switch(s)
    {
    case NON:
        return "non";
        break;
    case BEST:
        return "best";
        break;
    case WORST:
        return "worst";
        break;
    case LENGTH:
        return "length";
        break;
    }
    return "";
}


//
//

#endif // TYPEDEFS
