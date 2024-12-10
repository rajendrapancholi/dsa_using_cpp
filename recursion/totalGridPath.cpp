/**********************
Program Name        : The problem is to count all the possible paths on an mxn grid from top left(gred[0][0]) to bottom right(grid[m-1][n-1]). Having constraints that from each cell you can either move only to right or down.
Author              : Rajendra Pancholi
Date of creation    : 10/12/2024
Organization        : NIT Patna
***********************/
#include <iostream>
using namespace std;

int totalPath(int m, int n, int i, int j)
{
    // Base case
    if (i == m - 1 and j == n - 1)
        return 1;
    if (i >= m || j >= n)
        return 0;

    return totalPath(m, n, i + 1, j) + totalPath(m, n, i, j + 1);
}
int main()
{
    int m = 3, n = 3;
    int res = totalPath(m, n, 0, 0);
    cout << "Total path is: " << res << endl;

    return 0;
}