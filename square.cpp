/* You are given two 3×3 matrices in which one square is blank (which is marked by 0) and the other eight squares are filled with numbers from 1 to 8(with no repetition). Your task is to determine whether it is possible to reach the second matrix state from the first matrix state, if at each step only one number that is adjacent (up, down, left, or right) to the blank space can slide into the blank position

Input Format

For each test case: The first line contains 9 integers separated by spaces, representing the initial 3×3 matrix content in row-major representation. The next line contains 9 integers separated by spaces, representing the target 3×3 matrix content in row-major representation. Each matrix contains all integers from 0 to 8, where: 0 represents the blank space, The numbers 1 to 8 appear exactly once

Constraints
at each step only one number that is adjacent (up, down, left, or right) to the blank space can slide into the blank position. Diagonal Movement is not allowed.

Output Format
For each test case, output "YES" if it is possible to reach the final state starting from initial state in finite count of steps, and "NO" otherwise.

Sample Input 0
{8, 4, 1, 0, 7, 6, 3, 5, 2}
{5, 6, 8, 4, 3, 1, 2, 7, 0}
Sample Output 0
NO
Sample Input 1
{0, 5, 4, 8, 3, 2, 7, 6, 1}
{2, 5, 8, 0, 4, 6, 3, 1, 7}
Sample Output 1
YES
Sample Input 2
{5, 1, 7, 0, 4, 2, 3, 6, 8}
{5, 4, 7, 3, 2, 1, 8, 0, 6}
Sample Output 2
NO

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool helper(vector<vector<int>> &initail, vector<vector<int>> &target, int count, int currRow, int currCol, vector<vector<int>> &visited){
    // Base condition
    if(count > 9){
      for(int i=0; i<9; i++){
        for(int j=0; j<3; j++){
          if(initail[i%3]==target[i%3]) continue;
        }
        return false;
      }
      return true;
    }
    int row[] = {0, -1, 0, +1};
    int col[] = {+1, 0, -1, 0};

    for(int i=0; i< 4; i++){
      int newRow = currRow + row[i];
      int newCol = currCol + col[i];
      if(newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3 && visited[newRow][newCol]==0){ //check validity
        if(initail[newRow][newCol]==target[newRow][newCol]) continue;
        if(initail[currRow][currCol]==0){
          visited[currRow][currCol]=1;
          swap(initail[currRow][currCol], initail[newRow][newCol]);
          return helper(initail, target, count++, newRow, newCol, visited);
        }
      }
    }
  }
public:
  string solve(vector<vector<int>> initail, vector<vector<int>> target){
    vector<vector<int>> visited(3, vector<int>(3, 0));
    bool res = helper(initail, target, 0, 0, 0, visited);
    
    return res?"YES":"NO";
  }
};

int main() {
  // vector<int> initial(9), target(9);
  // vector<vector<int>> initial = {{8, 4, 1}, {0, 7, 6}, {3, 5, 2}}, target = {{5, 6, 8}, {4, 3, 1}, {2, 7, 0}};
  vector<vector<int>> initial = {{8, 4, 1}, {0, 7, 6}, {3, 5, 2}}, target = {{5, 6, 8}, {4, 3, 1}, {2, 7, 0}};


  // for(int i=0; i<9; i++){
  //   cin>>initial[i];
  // }
  // for(int i=0; i<9; i++){
  //   cin>>target[i];
  // }
  Solution sl;
  cout<<sl.solve(initial, target)<<endl;
  return 0;
}
