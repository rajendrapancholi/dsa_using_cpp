/**********************
Program Name        : Find the row with the maximum number of ones
Author              : Rajendra Pancholi
Date of creation    : 02/10/2024
Organization        : NIT Patna
***********************/

/*
Given a problem 2D array , where each row is sorted. Find the row with the maximum number of ones.
    0 0 1 1
    0 0 0 1
    0 1 1 1
 */

#include <iostream>
#include <vector>

using namespace std;

// M1: Function for find maximum ones in a row
/* int maxOnesRow(vector<vector<int>> v)
{
    int mxOnes = INT8_MIN;
    int mxOnesRow = -1;
    int col = v[0].size();
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == 1)
            {
                int countOnes = col - j;
                if (countOnes > mxOnes)
                {
                    mxOnes = countOnes;
                    mxOnesRow = i;
                }
            }
        }
    }

    return mxOnesRow;
}
 */

// M2: Function for find maximum ones in a row
int maxOnesRow(vector<vector<int>> v)
{
    int maxOnesRow = -1;
    int j = v[0].size() - 1;
    // Find leftmost 1's in 0th row
    while (j >= 0 && v[0][j] == 1)
    {
        maxOnesRow = 0;
        j--;
    }
    // Find rest of the rows
    for (int i = 0; i < v.size(); i++)
    {
        while (j >= 0 && v[i][j] == 1)
        {
            maxOnesRow = i;
            j--;
        }
    }
    return maxOnesRow;
}

int main()
{
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m));
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
        }
    }
    int result = maxOnesRow(vec);
    cout << "Maximum one's row(0 based index) is: " << result << endl;

    return 0;
}