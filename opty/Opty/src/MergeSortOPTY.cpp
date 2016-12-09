#include "MergeSortOPTY.h"
int MergeSortOPTY::comparatorINT(const int a,const int b)
{
    return a<b;
}
int MergeSortOPTY::sort(std::vector<int> &toSort)
{
//    LOG(DEBUG)<<"NIE DZIALA!!!!!!!!!!!!!!!!!!!!!";
    int *a =new int[toSort.size()];
    for(int i=0;i<toSort.size();i++)
    {
        a[i]=toSort[i];
    }
__sort(a,toSort.size(),sizeof(int));

}
int MergeSortOPTY::__sort (void *base, std::size_t nmemb, std::size_t size)
{
    int copy_mode;
    void *tmp;

    if (nmemb < 2)
        return 0;

    if (!(tmp = malloc (nmemb * size)))
    {
        errno = ENOMEM;
        return -1;
    }

    if ((((char *) base) - ((char *) 0)) % sizeof (long) == 0 && (size % sizeof (long)) == 0)
        copy_mode = 1;
    else if ((((char *) base) - ((char *) 0)) % sizeof (int) == 0 && (size % sizeof (int)) == 0)
        copy_mode = 2;
    else
        copy_mode = 0;

    msort (base, tmp, 0, nmemb - 1, size, copy_mode);

    free (tmp);

    return 0;
}
void  MergeSortOPTY::msort(void *array, void *buf, std::size_t low, std::size_t high, std::size_t size,
                           int copy_mode)
{
    char *a1, *al, *am, *ah, *ls, *hs, *lo, *hi, *b;
    size_t copied = 0;
    size_t mid;

    mid = MID (low, high);

    if (mid + 1 < high)
        msort (array, buf, mid + 1, high, size,copy_mode);

    if (mid > low)
        msort (array, buf, low, mid, size,copy_mode);

    ah = ((char *) array) + ((high + 1) * size);
    am = ((char *) array) + ((mid + 1) * size);
    a1 = al = ((char *) array) + (low * size);

    b = (char *) buf;
    lo = al;
    hi = am;

    do
    {
        ls = lo;
        hs = hi;

        if (lo > al || hi > am)
        {
            /* our last loop already compared lo & hi and found lo <= hi */
            lo += size;
        }

        while (lo < am && (lo<=hi))
            lo += size;

        if (lo < am)
        {
            if (copied == 0)
            {
                /* avoid copying the leading items */
                a1 = lo;
                ls = lo;
            }

            /* our last compare tells us hi < lo */
            hi += size;

            while (hi < ah &&(hi< lo) )
                hi += size;

            if (lo > ls)
            {
                MEMCOPY (b, ls, lo - ls);
                copied += (lo - ls);
                b += (lo - ls);
            }

            MEMCOPY (b, hs, hi - hs);
            copied += (hi - hs);
            b += (hi - hs);
        }
        else if (copied)
        {
            MEMCOPY (b, ls, lo - ls);
            copied += (lo - ls);
            b += (lo - ls);

            /* copy everything we needed to re-order back into array */
            MEMCOPY (a1, buf, copied);
            return;
        }
        else
        {
            /* everything already in order */
            return;
        }
    }
    while (hi < ah);

    if (lo < am)
    {
        MEMCOPY (b, lo, am - lo);
        copied += (am - lo);
    }

    MEMCOPY (a1, buf, copied);
}
