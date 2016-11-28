#include "WorstCaseMergeSort.h"
/*

Sort<BubbleSort,WorstCaseMergeSort,BestCase> a(std::vector<int>{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
 13, 14, 15, 16}});

    a.generateWorst();
a.print();
Should be:
{1, 9, 5, 13, 3, 11, 7, 15, 2, 10, 6,
 14, 4, 12, 8, 16}
*/
WorstCaseMergeSort::WorstCaseMergeSort() {}
WorstCaseMergeSort::~WorstCaseMergeSort() {}
WorstCaseMergeSort::generate(std::vector<int> &generator)
{
    generateWorstCase(&generator[0], 0, generator.size() - 1);

}


/// Function to join left and right subarray
int WorstCaseMergeSort::join(int arr[], int left[], int right[],int l, int m, int r)
{
    int i; // Used in second loop
    for (i = 0; i <= m - l; i++)
        arr[i] = left[i];

    for (int j = 0; j < r - m; j++)
        arr[i + j] = right[j];
}

// Function to store alternate elemets in left
// and right subarray
int WorstCaseMergeSort::split(int arr[], int left[], int right[],int l, int m, int r)
{
    for (int i = 0; i <= m - l; i++)
        left[i] = arr[i * 2];

    for (int i = 0; i < r - m; i++)
        right[i] = arr[i * 2 + 1];
}

// Function to generate Worst Case of Merge Sort
int WorstCaseMergeSort::generateWorstCase(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        // create two auxillary arrays
        int left[m - l + 1];
        int right[r - m];

        // Store alternate array elements in left
        // and right subarray
        split(arr, left, right, l, m, r);

        // Recurse first and second halves
        generateWorstCase(left, l, m);
        generateWorstCase(right, m + 1, r);

        // join left and right subarray
        join(arr, left, right, l, m, r);
    }
}
