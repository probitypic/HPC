#include <iostream>
using namespace std;

#define n 100

int main()
{
    srand(time(NULL));

    int *arr1 = new int[n];
    int *arr2 = new int[n];
    int *result = new int[n];

#pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        arr1[i] = rand() % 10000;
        arr2[i] = rand() % 10000;
    }

#pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        result[i] = arr1[i] + arr2[i];
    }

    cout << "array 1 : \n";

    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << ",";
    }

    cout << "\narray 2 : \n";

    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << ",";
    }

    cout << "\nresult : \n";

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << ",";
    }
}