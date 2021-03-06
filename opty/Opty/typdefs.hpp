

#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <vector>
#include <boost/preprocessor.hpp>
#include <iostream>
 #include <boost/multiprecision/cpp_int.hpp>


using namespace boost::multiprecision;


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
                                    (QUICK_OPTY)(MERGE_OPTY)
                                   )

DEFINE_ENUM_WITH_STRING_CONVERSIONS (TEST_OPTIONS,

                                     (RANDOM)(BEST)(WORST)(LENGTH)
                                    )


typedef std::vector<int>::iterator VintIter;
//typedef std::pair<VintIter,VintIter> VintIterPair;


const int MAX_VECTOR=8000;
class TimeComprasions
{
public:


    TimeComprasions& operator+=(const TimeComprasions& rhs)
    {
        this->comprasions=this->comprasions+rhs.comprasions;
        this->time=this->time+rhs.time;
        return *this;
    }
    TimeComprasions& operator/=(int value)
    {
        this->comprasions=this->comprasions/value;
        this->time=this->time/value;
        return *this;
    }
    std::ostream& operator<< (std::ostream& stream)
    {
        stream<<"c="<<this->comprasions<<" t="<<this->time<<std::endl;
        return stream;
    }

    TimeComprasions(double t,uint256_t c):time(t),comprasions(c) {};
    double time;
    uint256_t comprasions;
};
//    std::ostream& operator<< (std::ostream& stream, const TimeComprasions & tc)
//    {
//        stream<<"c="<<tc.comprasions<<" t="<<tc.time<<std::endl;
//        return stream;
//    }
//
//

#endif // TYPEDEFS
