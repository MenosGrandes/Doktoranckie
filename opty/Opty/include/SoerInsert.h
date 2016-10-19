#ifndef SOERINSERT_H
#define SOERINSERT_H

#include <Sort.h>


class SoerInsert : public Sort
{
    public:
        SoerInsert(int n, int max);
        virtual ~SoerInsert();
        void _sort();
    protected:

    private:
};

#endif // SOERINSERT_H
