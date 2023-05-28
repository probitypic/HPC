#include <iostream>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
// #include <omp.h>
#include <vector>

using namespace std;
int main()
{
    int r = 3, c = 2;
    int matrix[r][c], vector[c], out[r];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            matrix[i][j] = 1;
        }
    }

    cout << " Input matrix :\n\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < c; i++)
    {
        vector[i] = 3;
    }
    cout << "Input col-vector\n\n";
    for (int i = 0; i < c; i++)
    {
        cout << vector[i] << endl;
    }
    cout << endl;

#pragma omp parallel for
    for (int i = 0; i < r; i++)
    {
        out[i] = 0;

        for (int j = 0; j < c; j++)
        {
            out[i] += matrix[i][j] * vector[j];
        }
    }

    cout << "Resultant col-vector\n\n";
    for (int i = 0; i < r; i++)
    {
        cout << out[i] << endl;
    }
}