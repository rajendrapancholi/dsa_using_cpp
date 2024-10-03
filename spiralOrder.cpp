/**********************
Program Name        : Spiral order of matrix
Author              : Rajendra Pancholi
Date of creation    : 03/10/2024
Organization        : NIT Patna
***********************/

/*
Given an NxM matrix 'A', return all elements of the matrix in spiral order.
    1  2  3  4
    5  6  7  8
    9 10 11 12
 */
#include <iostream>
#include <vector>
#include <iomanip> // it contains setw(size_in_int) method
using namespace std;

// Method for print spilar order of the matrix.]
void spiralOrder(vector<vector<int>> &mat)
{
    int left = 0, top = 0;
    int right = mat[0].size() - 1; // number of column of first row
    int bottom = mat.size() - 1;   // number of row
    int direction = 0;             // 0 -> Left2Right, 1 -> Top2Bottom, 2 -> Right2Left, 3 -> Bottom2Top
    cout << endl
         << "Spiral order is:" << endl;
    while (left <= right && top <= bottom)
    {
        // Using if else if conditions
        /* if (direction == 0) // Left to Right
        {
            for (int col = left; col <= right; col++)
            {
                cout << mat[top][col] << " ";
            }
            top++;
        }
        else if (direction == 1) // Top to Bottom
        {
            for (int row = top; row <= bottom; row++)
            {
                cout << mat[row][right] << " ";
            }
            right--;
        }
        else if (direction == 2) // Right to Left
        {
            for (int col = right; col >= left; col--)
            {
                cout << mat[bottom][col] << " ";
            }
            bottom--;
        }
        else // Bottom to Top
        {
            for (int row = bottom; row >= top; row--)
            {
                cout << mat[row][left] << " ";
            }
            left++;
        } */

        // Using switch case
        switch (direction)
        {
        case 0: // Left to Right
            for (int col = left; col <= right; col++)
            {
                cout << mat[top][col] << " ";
            }
            top++;
            break;

        case 1: // Top to Bottom
            for (int row = top; row <= bottom; row++)
            {
                cout << mat[row][right] << " ";
            }
            right--;
            break;

        case 2: // Right to Left
            for (int col = right; col >= left; col--)
            {
                cout << mat[bottom][col] << " ";
            }
            bottom--;
            break;

        case 3: // Bottom to Top
            for (int row = bottom; row >= top; row--)
            {
                cout << mat[row][left] << " ";
            }
            left++;
            break;
        }
        direction = (direction + 1) % 4;
    }
}

int main()
{
    int n, m;
    cout << "Enter the order of matrix(n,m): ";
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    // Taking elements from user
    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << endl;
    // Display array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(2) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    // invoked spiralOrder()
    spiralOrder(matrix);
    return 0;
}