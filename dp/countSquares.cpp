/* Count Square Submatrices with All 1s | DP on Rectangles
Problem Statement: Given an n * m matrix of ones and zeros, return how many square submatrices have all ones.

Examples
Example 1:
Input: matrix = [ [0,1,1,1],
[1,1,1,1],
[0,1,1,1]]
Output: 15
Explanation: 
There are 10 squares of size 1.
There are 4 squares of size 2.
There is  1 square of size 3.
Total number of squares = 10 + 4 + 1 = 15.

Example 2:
Input: matrix =  [ [1,0,1],
[1,1,0],
[1,1,0]]
Output: 7
Explanation: 
There are 6 squares of size 1.  
There is 1 square of size 2. 
Total number of squares = 6 + 1 = 7.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findSquares(vector<vector<int>> &mat){
    int squares = 0;
    int nr = mat.size(), nc = mat[0].size() ;

    vector<vector<int>> dp(nr, vector<int>(nc, 0));
    // fill first row and first column according to the matrix
    for(int i = 0; i < nc; i++)
      dp[0][i] = mat[0][i];
    
    for(int i = 0; i < nr; i++)
      dp[i][0] = mat[i][0];
    
    for(int row = 1; row < nr; row++){
      for(int col = 1; col < nc; col++){
        if(mat[row][col] == 1){
          // min(left, up, diagonal)
          int minEle = min(dp[row][col - 1], min(dp[row - 1][col], dp[row - 1][col - 1]));
          dp[row][col] = minEle + 1;
        }
      }
    }
    for(auto it: dp)
      for(auto el: it) squares += el;

    return squares;
  }
};

int main() {
  vector<vector<int>> matrix = {{0,1,1,1}, {1,1,1,1}, {0,1,1,1}};
  Solution sl;
  cout<<sl.findSquares(matrix)<<endl;
  return 0;
}
