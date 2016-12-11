#ifndef TIMER_H
#define TIMER_H

#include "Sort.h"

#ifdef _WIN32
#include <windows.h>

class Timer
{
public:
    Timer() =default;
    ~Timer() =default;
    template <class SortMethod>
    TimeComprasions measureTimeAndComprasions( SortMethod *s)
    {
        StartCounter();
        int comprasions= s->_sort();
        double ret=GetCounter();
        return TimeComprasions(ret,comprasions);
    }

    double PCFreq = 0.0;
    __int64 CounterStart = 0;
    void StartCounter()
    {
        LARGE_INTEGER li;
        if(!QueryPerformanceFrequency(&li))
            std::cout << "QueryPerformanceFrequency failed!\n";

        PCFreq = double(li.QuadPart)/1000.0;

        QueryPerformanceCounter(&li);
        CounterStart = li.QuadPart;
    }
    double GetCounter()
    {
        LARGE_INTEGER li;
        QueryPerformanceCounter(&li);
        return double(li.QuadPart-CounterStart)/PCFreq;
    }
};
#elif __linux__
#define BILLION 1000000000L
class Timer
{
public:
    Timer() =default;
    ~Timer() =default;
    template <class SortMethod>
    TimeComprasions measureTimeAndComprasions( SortMethod *s)
    {
    constexpr double NANOSECONDS_TO_MILLISECONDS = 1.0 / 1000000.0;
        timespec start, end;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
        int comprasions= s->_sort();
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);


        return TimeComprasions((BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec) * NANOSECONDS_TO_MILLISECONDS,comprasions);
    }

};
#endif // _WIN32
#endif // TIMER_H
