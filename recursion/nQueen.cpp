/**********************
Program Name        : Implement N-Queen problem.
Author              : Rajendra Pancholi
Date of creation    : 15/12/2024
Organization        : NIT Patna
***********************/
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n)
{
    for (int i = 0; i < n; i++)
    {
        // Horizontal check
        if (board[row][i] == 'Q')
            return false;
        // Vertical check
        if (board[i][col] == 'Q')
            return false;
    }
    // Left diagonal check
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    // Right diagonal check
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void nQueen(vector<string> &board, int row, int n, vector<vector<string>> &ans)
{
    if (row >= n)
    {
        ans.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 'Q';
            nQueen(board, row + 1, n, ans);
            board[row][col] = '.';
        }
    }
}
int main()
{
    int n = 4;
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    nQueen(board, 0, n, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Possibility - " << i + 1 << endl;
        for (int j = 0; j < ans[0].size(); j++)
        {
            for (int k = 0; k < ans[0].size(); k++)
            {
                cout << ans[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}