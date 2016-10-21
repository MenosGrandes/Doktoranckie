#ifndef TIMER_H
#define TIMER_H

#include "Sort.h"

#include <chrono>
class Timer
{
public:
    Timer();
    ~Timer();
    int measure(Sort *s)
    {
        auto start = std::chrono::steady_clock::now();
        s->_sort();

        auto end = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>( end - start).count();
    }
protected:

private:
};

#endif // TIMER_H
