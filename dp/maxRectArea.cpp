/* Maximum Rectangle Area with all 1's
Problem Statement: Given a m x n binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Examples
Input: matrix = [[1,0,1,0,0],[1,0,1,1,1],[1,1,1,1,1],[1,0,0,1,0]]
Output: 6
Explanation: The highlighted part depicts the rectangle with the largest area i.e. 6

Input:  matrix = [[1]]
Output: 1
Explanation: In this case, there is only one rectangle with area 1.
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
  int maxHistoArea(vector<int> &arr){
    int n = arr.size();
    int maxArea = 0;
    stack<int> st;
    for(int i = 0; i <= n; i++){
      int currHeight = (i == n) ? 0 : arr[i];
      while(!st.empty() && currHeight < arr[st.top()]){
        int height = arr[st.top()];
        st.pop();
        int width = (st.empty())? i: i - st.top() - 1;
        maxArea = max(maxArea, height * width);
      }
      st.push(i);
    }
    return maxArea;
  }
public:
  int maxRectangleArea(vector<vector<int>> &mat){
    int maxArea = 0;
    vector<int> histoGrm(mat[0].size(), 0);
    for(int row = 0; row < mat.size(); row++){
      for(int col = 0; col < mat[0].size(); col++){
        if(mat[row][col] == 0 && histoGrm[col] > 0){
          histoGrm[col] = 0;
        } else
          histoGrm[col] += mat[row][col]; 
      }
      maxArea = max(maxArea, maxHistoArea(histoGrm));
    }
    return maxArea;
  }
};

int main() {
  vector<vector<int>> matrix = {{1,0,1,0,0}, {1,0,1,1,1}, {1,1,1,1,1}, {1,0,0,1,0}};
  Solution sl;
  cout<<sl.maxRectangleArea(matrix)<<endl;
  return 0;
}
