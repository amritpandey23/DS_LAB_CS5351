// author: Amrit Pandey, 207907
// date: 28-06-2021
//  Implement HeapSort Sorting Algorithm

#include <iostream>
#include <stdio.h>
using namespace std;

void heapify(int a[], int n, int i)
{
    int lgst, l, r;
    lgst = i;
    l = 2 * i + 1;
    r = 2 * i + 2;

    if (l < n && a[l] > a[lgst])
    {
        lgst = l;
    }

    if (r < n && a[r] > a[lgst])
    {
        lgst = r;
    }

    if (lgst != i)
    {
        swap(a[i], a[lgst]);
        heapify(a, n, lgst);
    }
}

void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int a[] = {-2, 11, 34, -90, 23, 56};
    int n = 6;
    heapSort(a, n);
    cout << "SORT: ";
    printArray(a, n);
    
    // test cases:
    /*
    6 -23 0 90 12 34 11
    5 12 -90 78 12 56
    */

    int x;
    scanf("%d", &x);
    int b[x];
    for (int i = 0; i < x; i++)
    {
        scanf("%d", &b[i]);
    }
    heapSort(b, x);
    cout << "SORT: ";
    printArray(b, x);
}
