#include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <omp.h>
using namespace std;

void parallelBubbleSort(int *array, int n)
{
    int i, j;

#pragma omp parallel for private(i, j) shared(array)
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                // Swap elements
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void merge(int arr[], int l, int m, int r)
{

    int i = l;
    int j = m + 1;
    int temp[r + 1];
    int k = l;

    while (i <= m && j <= r)
    {

        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    if (i > m)
    {
        while (j <= r)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= m)
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
    }

    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i];
    }
}

void parallel_merge_sort(int arr[], int l, int r)
{

    if (l < r)
    {

        int mid = (l + r) / 2;
        {
#pragma omp section
            parallel_merge_sort(arr, l, mid);
#pragma omp section
            parallel_merge_sort(arr, mid + 1, r);
        }

        merge(arr, l, mid, r);
    }
}

int main()
{

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    cout << "Original Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    int choice;
    cout << "Enter 1 for Parallel Bubble Sort or 2 for Parallel Merge Sort: ";
    cin >> choice;

    if (choice == 1)
    {
        parallelBubbleSort(arr, n);
    }
    else if (choice == 2)
    {
        parallel_merge_sort(arr, 0, n - 1);
    }
    else
    {
        cout << "Invalid choice. Exiting program." << endl;
        return 0;
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}