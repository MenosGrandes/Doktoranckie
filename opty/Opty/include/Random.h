#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <cstdlib>
#include <ctime>
class Random
{
private:

    Random() {};
    Random(const Random&r) {};

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


};



#endif // RANDOM_H

