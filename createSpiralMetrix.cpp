/**********************
Program Name        : Spiral matrix
Author              : Rajendra Pancholi
Date of creation    : 03/10/2024
Organization        : NIT Patna
***********************/

/*
create an NxM matrix 'A', return the matrix in spiral order.
 1  2  3  4
12 13 14  5
11 16 15  6
10  9  8  7
 */
#include <iostream>
#include <vector>
#include <iomanip> // it contains setw(size_in_int) method
using namespace std;

// Method for print  increasing spilar matrix.
void incSpiralMatrix(vector<vector<int>> &mat)
{
    int left = 0, top = 0, ele = 1;
    int right = mat[0].size() - 1; // number of column of first row
    int bottom = mat.size() - 1;   // number of row
    int direction = 0;             // 0 -> Left2Right, 1 -> Top2Bottom, 2 -> Right2Left, 3 -> Bottom2Top
    cout << endl
         << "Spiral matrix is:" << endl;
    while (left <= right && top <= bottom)
    {
        // Using if else if conditions
        /* if (direction == 0) // Left to Right
        {
            for (int col = left; col <= right; col++)
            {
                mat[top][col] = ele;
                ele++;
            }
            top++;
        }
        else if (direction == 1) // Top to Bottom
        {
            for (int row = top; row <= bottom; row++)
            {
                mat[row][right] = ele;
                ele++;
            }
            right--;
        }
        else if (direction == 2) // Right to Left
        {
            for (int col = right; col >= left; col--)
            {
                mat[bottom][col] = ele;
                ele++;
            }
            bottom--;
        }
        else // Bottom to Top
        {
            for (int row = bottom; row >= top; row--)
            {
                mat[row][left] = ele;
                ele++;
            }
            left++;
        } */

        // Using switch case
        switch (direction)
        {
        case 0: // Left to Right
            for (int col = left; col <= right; col++)
            {
                mat[top][col] = ele;
                ele++;
            }
            top++;
            break;

        case 1: // Top to Bottom
            for (int row = top; row <= bottom; row++)
            {
                mat[row][right] = ele;
                ele++;
            }
            right--;
            break;

        case 2: // Right to Left
            for (int col = right; col >= left; col--)
            {
                mat[bottom][col] = ele;
                ele++;
            }
            bottom--;
            break;

        case 3: // Bottom to Top
            for (int row = bottom; row >= top; row--)
            {
                mat[row][left] = ele;
                ele++;
            }
            left++;
            break;
        }
        direction = (direction + 1) % 4;
    }
}

// Method for print  decreasing spilar matrix.
void decSpiralMatrix(vector<vector<int>> &mat)
{
    int left = 0, top = 0, ele = mat[0].size() * mat.size();
    int right = mat[0].size() - 1; // number of column of first row
    int bottom = mat.size() - 1;   // number of row
    int direction = 0;             // 0 -> Left2Right, 1 -> Top2Bottom, 2 -> Right2Left, 3 -> Bottom2Top
    cout << endl
         << "Spiral matrix is:" << endl;
    while (left <= right && top <= bottom)
    {
        // Using if else if conditions
        /* if (direction == 0) // Left to Right
        {
            for (int col = left; col <= right; col++)
            {
                mat[top][col] = ele;
                ele--;
            }
            top++;
        }
        else if (direction == 1) // Top to Bottom
        {
            for (int row = top; row <= bottom; row++)
            {
                mat[row][right] = ele;
                ele--;
            }
            right--;
        }
        else if (direction == 2) // Right to Left
        {
            for (int col = right; col >= left; col--)
            {
                mat[bottom][col] = ele;
                ele--;
            }
            bottom--;
        }
        else // Bottom to Top
        {
            for (int row = bottom; row >= top; row--)
            {
                mat[row][left] = ele;
                ele--;
            }
            left++;
        } */

        // Using switch case
        switch (direction)
        {
        case 0: // Left to Right
            for (int col = left; col <= right; col++)
            {
                mat[top][col] = ele;
                ele--;
            }
            top++;
            break;

        case 1: // Top to Bottom
            for (int row = top; row <= bottom; row++)
            {
                mat[row][right] = ele;
                ele--;
            }
            right--;
            break;

        case 2: // Right to Left
            for (int col = right; col >= left; col--)
            {
                mat[bottom][col] = ele;
                ele--;
            }
            bottom--;
            break;

        case 3: // Bottom to Top
            for (int row = bottom; row >= top; row--)
            {
                mat[row][left] = ele;
                ele--;
            }
            left++;
            break;
        }
        direction = (direction + 1) % 4;
    }
}

// Method for spiral matrix with increasing alphabets
void incalphabetsSpiralMatrix(vector<vector<int>> &mat)
{
    int left = 0, top = 0;
    char ele = 'A';
    int right = mat[0].size() - 1; // number of column of first row
    int bottom = mat.size() - 1;   // number of row
    int direction = 0;             // 0 -> Left2Right, 1 -> Top2Bottom, 2 -> Right2Left, 3 -> Bottom2Top
    cout << endl
         << "Spiral matrix is:" << endl;
    while (left <= right && top <= bottom)
    {
        // M1: Using if else if conditions
        //  Try yourself

        // M1: Using switch case
        switch (direction)
        {
        case 0: // Left to Right
            for (int col = left; col <= right; col++)
            {
                mat[top][col] = ele;
                ele++;
            }
            top++;
            break;

        case 1: // Top to Bottom
            for (int row = top; row <= bottom; row++)
            {
                mat[row][right] = ele;
                ele++;
            }
            right--;
            break;

        case 2: // Right to Left
            for (int col = right; col >= left; col--)
            {
                mat[bottom][col] = ele;
                ele++;
            }
            bottom--;
            break;

        case 3: // Bottom to Top
            for (int row = bottom; row >= top; row--)
            {
                mat[row][left] = ele;
                ele++;
            }
            left++;
            break;
        }
        direction = (direction + 1) % 4;
    }
}

// Method for spiral matrix with decreasing alphabets
void decalphabetsSpiralMatrix(vector<vector<int>> &mat)
{
    int left = 0, top = 0;
    char ele = ('A' - 1) + (mat[0].size() * mat.size());
    int right = mat[0].size() - 1; // number of column of first row
    int bottom = mat.size() - 1;   // number of row
    int direction = 0;             // 0 -> Left2Right, 1 -> Top2Bottom, 2 -> Right2Left, 3 -> Bottom2Top
    cout << endl
         << "Spiral matrix is:" << endl;
    while (left <= right && top <= bottom)
    {
        // M1: Using if else if conditions
        //  Try yourself

        // M1: Using switch case
        switch (direction)
        {
        case 0: // Left to Right
            for (int col = left; col <= right; col++)
            {
                mat[top][col] = ele;
                ele--;
            }
            top++;
            break;

        case 1: // Top to Bottom
            for (int row = top; row <= bottom; row++)
            {
                mat[row][right] = ele;
                ele--;
            }
            right--;
            break;

        case 2: // Right to Left
            for (int col = right; col >= left; col--)
            {
                mat[bottom][col] = ele;
                ele--;
            }
            bottom--;
            break;

        case 3: // Bottom to Top
            for (int row = bottom; row >= top; row--)
            {
                mat[row][left] = ele;
                ele--;
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

    // For increasing order
    // incSpiralMatrix(matrix);

    // For decreasing order
    // decSpiralMatrix(matrix);

    // For increasing order
    // incalphabetsSpiralMatrix(matrix);

    // For decreasing order
    decalphabetsSpiralMatrix(matrix);

    /*     for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << setw(2) << matrix[i][j] << " ";
            }
            cout << endl;
        } */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << (char)matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}