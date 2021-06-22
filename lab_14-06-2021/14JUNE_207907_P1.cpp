// author: Amrit Pandey, 207907
// date: 14-06-2021
// Design a program to implement the following sorting algorithms on integer data.

// Bubble Sort [Optional]
// Selection Sort [Optional]
// Insertion Sort
// Merge Sort
// Quick Sort
// The program should have a menu with options to

// generate an array of random numbers,
// call the various sorting algorithms on the array, and
// print the array.
// [The student should practice to write sorting algorithms on other data types including structures and class objects; and other possible ways they can be implemented/used]


            /*  With a properly defined function, it becomes unecessary to 
                know how it is done, knowing what is been done is sufficient.

                - Brian Kernighan (Author of Book "The C Programming Language")
            */


#include <iostream>
using namespace std;

int menu();                             // choice menu
void fillArray(int[], int);             // generate random INT in array
void printArray(int[], int);            // printing array
void insertionSort(int[], int);         // insertion sort - iterative
void mergeArray(int[], int, int, int);  // merge array
void mergeSort(int[], int, int);        // merge sort - recursive
int partition(int[], int, int);         
void quickSort(int[], int, int);        // quick sort
void bubbleSort(int[], int);            // bubble sort
void runner();                          // main program driver

int menu()
{
    cout << "[1] Insertion Sort" << endl;
    cout << "[2] Merge Sort" << endl;
    cout << "[3] Quick Sort" << endl;
    cout << "[4] Bubble Sort" << endl;
    cout << "[0] Exit" << endl;
    cout << "[IN] : ";
    int res;
    cin >> res;
    return res;
}

int main()
{
    runner();
}

void fillArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
}

void printArray(int arr[], int size)
{
    cout << "[OUT] : [";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "\b\b]" << endl;
}

void insertionSort(int arr[], int n) 
{
    if (n == 1)
    {
        return;
    }

    int i, j, x;

    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = arr[i];
        while (j > -1 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

void mergeArray(int arr[], int low, int mid, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    int tmp[high + 1];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        tmp[k++] = arr[i++];
    }
    while (j <= high)
    {
        tmp[k++] = arr[j++];
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = tmp[i];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        mergeArray(arr, low, mid, high);
    }
}

int partition(int arr[], int low, int high)
{
    int i, j, pvt;
    pvt = arr[low];
    i = low - 1;
    j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pvt);
        do
        {
            j--;
        } while (arr[j] > pvt);
        if (i >= j)
        {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int part = partition(arr, low, high);
        quickSort(arr, low, part);
        quickSort(arr, part + 1, high);
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j, flag;

    for (i = 0; i < n - 1; i++)
    {

        for (j = 0; j < n - 1 - i; j++)
        {
            flag = 0;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void runner()
{
    int n;
    while (true)
    {
        cout << "[ENTER SIZE OR 0 TO EXIT] : ";
        cin >> n;
        if (n == 0)
        {
            cout << "Exiting program, Bye." << endl;
            exit(0);
        }
        if (n <= 1)
        {
            cout << "[OUT]: Enter size greater than 1" << endl;
            continue;
        }
        int arr[n];
        fillArray(arr, n);
        printArray(arr, n);
        switch (menu())
        {
        case 1:
        {
            insertionSort(arr, n);
            cout << "Sorted Array = ";
            printArray(arr, n);
            break;
        }
        case 2:
        {
            mergeSort(arr, 0, n);
            cout << "Sorted Array = ";
            printArray(arr, n);
            break;
        }
        case 3:
        {
            quickSort(arr, 0, n);
            cout << "Sorted Array = ";
            printArray(arr, n);
            break;
        }
        case 4:
        {
            bubbleSort(arr, n);
            cout << "Sorted Array = ";
            printArray(arr, n);
            break;
        }
        default:
        {
            cout << "[OUT] : Invalid choice, try again." << endl;
            break;
        }
        }
    }
}


