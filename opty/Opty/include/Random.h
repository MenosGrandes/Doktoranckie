#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <algorithm>
class Random
{
private:

    Random() {};
    Random(const Random&r);

    ~Random() {};

public:
    static Random& getInstance()
    {
        static Random instance;
        return instance;
    }
    int generate(int min,int max)
    {
        return ( rand() % max ) + min;
    }
    std::vector<int> generateRandomVector(int min,int max,int n)
    {
        std::vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            v[i]=generate(min,max);
        }
        return v;
    }

};



#endif // RANDOM_H

