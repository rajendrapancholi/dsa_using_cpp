/**********************
Program Name        : Rotation of matrix
Author              : Rajendra Pancholi
Date of creation    : 03/10/2024
Organization        : NIT Patna
***********************/

/*
Given a square matrix , turn it by 90 degrees in a clockwise direction without using any extra array.
    1 2 3       7 4 1
    4 5 6  -->  8 5 2
    7 8 9       9 6 3
 */
#include <iostream>
#include <algorithm> // it contains reverse(start, end) function
#include <vector>

using namespace std;

// Fuction for rotate matrix
void rotateMatrix(vector<vector<int>> &mat)
{
    // Transpose of matrix
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
    // Reverse of each row
    for (int i = 0; i < mat.size(); i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main()
{
    int n;
    cout << "Enter size of matrix (NxN): ";
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    rotateMatrix(mat);
    cout << "After reverse(90degrees) matrix is:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
