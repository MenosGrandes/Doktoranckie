#ifndef SortInsert_H
#define SortInsert_H

#include "Sort.h"


class SortInsert : public Sort
{
public:
    SortInsert(int n, int max);
    SortInsert(int n, int*tab);

    ~SortInsert();
    void _sort();
protected:

private:
};

#endif // SortInsert_H
