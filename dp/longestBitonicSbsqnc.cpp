/* Longest Bitonic Subsequence
Problem Statement: Given an array arr of n integers, the task is to find the length of the longest bitonic sequence. A sequence is considered bitonic if it first increases, then decreases. The sequence does not have to be contiguous.

Examples
Example 1:
Input:
 arr = [5, 1, 4, 2, 3, 6, 8, 7]
Output:
 6
Explanation:
  
The longest bitonic sequence is [1, 2, 3, 6, 8, 7] with a length of 6.
The sequence increases from 1 to 8 and then decreases at 7.

Example 2:
Input:
 arr = [10, 20, 30, 40, 50, 40, 30, 20]
Output:
 8
Explanation:
 The entire array is bitonic, increasing up to 50 and then decreasing. The length of the bitonic sequence is 8.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int longestBitonicSubsequenc(vector<int> &arr){
    int n = arr.size(), maxLen = 0;

    vector<int> dp1(n, 1), dp2(n, 1);

    for(int i = 0; i < n; i++){
      for(int j = 0; j < i; j++){
        if(arr[j] < arr[i] && dp1[i] < dp1[j] + 1){
          dp1[i] = dp1[j] + 1;
        }
      }
    }
    
    for(int i = n - 1; i >= 0; i--){
      for(int j = n - 1; j > i; j--){
        if(arr[j] < arr[i] && dp2[i] < dp2[j] + 1){
          dp2[i] = dp2[j] + 1;
        }
      }
    }

    for(int i = 0; i < n; i++)
      if(maxLen < dp1[i] + dp2[i])
        maxLen = dp1[i] + dp2[i];
 
    return maxLen - 1;
  }
};

int main() {
  vector<int> arr = {10, 20, 30, 40, 50, 40, 30, 20};
  Solution sl;
  cout<<sl.longestBitonicSubsequenc(arr)<<endl;
  return 0;
}
