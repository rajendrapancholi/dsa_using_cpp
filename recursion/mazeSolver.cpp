/**********************
Program Name        : Implement Maze Solver.
Author              : Rajendra Pancholi
Date of creation    : 15/12/2024
Organization        : NIT Patna
***********************/
#include <iostream>
#include <vector>
using namespace std;

void mazeSolver(vector<vector<int>> &mat, int row, int col, int n, vector<string> &ans, string result)
{
    // Base case (result)
    if (row >= n - 1 && col >= n - 1)
    {
        ans.push_back(result);
        return;
    }
    // Check overflow OR out of bound of the matrix.
    if (row < 0 || col < 0 || row >= n || col >= n)
    {
        return;
    }
    if (mat[row][col] != 1)
    {
        return;
    }

    mat[row][col] = -1;
    mazeSolver(mat, row - 1, col, n, ans, result + "U"); // UP
    mazeSolver(mat, row + 1, col, n, ans, result + "D"); // DOWN
    mazeSolver(mat, row, col - 1, n, ans, result + "L"); // LEFT
    mazeSolver(mat, row, col + 1, n, ans, result + "R"); // RIGHT
    mat[row][col] = 1;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 1}};
    vector<string> ans;
    mazeSolver(mat, 0, 0, mat.size(), ans, "");
    for (auto ele : ans)
    {
        cout << ele << endl;
    }

    return 0;
}