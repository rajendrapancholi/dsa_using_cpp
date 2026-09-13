/* Program to generate Pascal's Triangle
Write a program to generate Pascal's triangle. In Pascal’s triangle, each number is the sum of the two numbers directly above it as shown in the figure below:

Examples
Input: N = 5, r = 5, c = 3 
Output: Element at position (r, c): 6
N-th row of Pascal’s triangle: 1 4 6 4 1
First n rows of Pascal’s triangle:
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1  
Explanation: Pascal triangle for first 5 rows is shown above.
Input: N = 1, r = 1, c = 1
Output: Element at position (r, c): 1
N-th row of Pascal’s triangle: 1
First n rows of Pascal’s triangle:
1  
Explanation: N = 1 is the base case fof a pascal's triangle. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> generate(int numRows) { 
        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++){
            vector<int> t_arr(i+1, 1);
            for(int j = 1; j < i; j++){
                t_arr[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(t_arr);
        }
        return res;
    }
public:
    int pascalTriangle(int N, int r, int c) {
        // vector<vector<int>> pT = generate(N); // tc: O(N^2); N -> numRows
        // return pT[r-1][c-1];

        int n = r-1, k = c-1, res = 1; // tc O(min(c, r-c))
        for(int i = 0; i < k; i++){
            res *= n - i;
            res /= i + 1;
        }
        return res;
    }
};

int main() {
    // Fast I/O Optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 5, r = 5, c = 3;
    // Output: Element at position (r, c): 6   
    Solution sl;
    auto result = sl.pascalTriangle(N, r, c);
    
    cout << result << "\n";
    
    return 0;
}