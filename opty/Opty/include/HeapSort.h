#ifndef HEAPSORT_H
#define HEAPSORT_H


class HeapSort
{
    public:
void sort(std::vector<int>& toSort)
{
//    build_maxheap(&toSort[0],toSort.size()-1);
//    heapsort(&toSort[0],toSort.size()-1);
}

    private:
void max_heapify(int *a, int i, int n)
{

    int temp = a[i];
    int j = 2*i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j+1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a[j/2] = temp;
    return;
}
void heapsort(int *a, int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heapify(a, 1, i - 1);
    }
}
void build_maxheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a, i, n);
    }
}

};

#endif // HEAPSORT_H
