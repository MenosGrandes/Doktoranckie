#ifndef TIMER_H
#define TIMER_H

#include "Sort.h"
#include <windows.h>

class Timer
{
public:
    Timer();
    ~Timer();

    long long measureWindows( Sort *s)
    {
        StartCounter();
        s->_sort();
        long long ret=GetCounter();
        return ret;
    }
protected:

private:
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

#endif // TIMER_H
