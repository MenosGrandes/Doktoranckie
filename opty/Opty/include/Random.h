#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <cstdlib>
#include <ctime>
class Random
{
private:

    Random()
    {
        srand(time(0));
    };
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
    void generateRandomIntTab(int n,int*tab,int min,int max)
{
    for(int i=0; i<n; i++)
    {
        tab[i]=Random::getInstance().generate(min,max);
    }
}
};



#endif // RANDOM_H

