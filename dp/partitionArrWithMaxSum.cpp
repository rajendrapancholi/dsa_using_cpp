/* Partition Array for Maximum Sum
Problem Description: Given an integer array arr with length n, and an integer k, you may partition arr into one or more contiguous sub-arrays, where each sub-array has length in the range [1, k] (both inclusive).
After you pick a partition, replace every element in each sub-array with the maximum value found in that sub-array. The array is modified in-place for the purpose of computing the total. Return the largest possible sum of the entire array after performing exactly one such partition-and-replace operation.

Examples
Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: The partition will be the following to get the largest sum: [1, 15, 7 | 9 | 2, 5, 10]. 
After replacing the elements of each subarray with its maximum, the array will look like this: [15,15,15,9,10,10,10] and the sum will be 84.
Input: arr = [2,2,2,2], k = 2
Output: 8
Explanation: Partition as [2,2 | 2,2]; each sub-array’s max is 2. The array stays [2,2,2,2] and the sum is 8.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int helper(int i, int k, int n, vector<int> &arr, vector<int> &dp){
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];
    int maxEle = 0, maxSum = 0;
    for(int idx = i; idx < i + k && idx < n; idx++){
      int len = idx - i + 1;
      maxEle = max(maxEle, arr[idx]);
      int currSum = maxEle * len + helper(idx + 1, k, n, arr, dp);
      maxSum = max(maxSum, currSum);
    }
    return dp[i] = maxSum;
  }
public:
  int findMaxPartitionMaxSum(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> dp(n, -1);
    return helper(0, k, n, arr, dp);
  }

  int findMaxPartitionMaxSumTab(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> dp(n, 0);
    for(int i = n - 1; i >= 0; i--){
      int maxEle = 0, maxSum = 0;
      for(int idx = i; idx < i + k && idx < n; idx++){
        int len = idx - i + 1;
        maxEle = max(maxEle, arr[idx]);
        int currSum = maxEle * len + dp[idx + 1];
        maxSum = max(maxSum, currSum);
      }
      dp[i] = maxSum;
    }
    return  dp[0];
  }
};

int main() {
  vector<int> arr = {1,15,7,9,2,5,10};
  int k = 3;

  Solution sl;
  cout<<sl.findMaxPartitionMaxSum(arr, k)<<endl;
  cout<<sl.findMaxPartitionMaxSumTab(arr, k)<<endl;
  return 0;
}
