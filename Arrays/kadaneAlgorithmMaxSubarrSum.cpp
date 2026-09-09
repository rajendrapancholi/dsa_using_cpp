// Kadane's Algorithm : Maximum Subarray Sum in an Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSubarrSum(vector<int> &nums) {
    int ans = INT_MIN, n = nums.size();
    // Brute force, TC-> O(n^2)
    /* for(int i = 0; i < n; i++){
      int temp = nums[i];
      for(int j = i+1; j < n; j++){
        temp += nums[j];
        ans = max(ans, temp);
      }

      return ans;
    */

    // Kadane's algo O(n)
    int currSum = 0, maxSum = 0;
    for (int e : nums) {
      currSum += e;
      if (currSum < 0)
        currSum = 0;
      maxSum = max(maxSum, currSum);
    }
    return maxSum;
  }
  vector<int> maxSubarrSumEle(vector<int> &nums) {
    // Kadane's algo O(n)
    long long maxi = LLONG_MIN;
    long long sum = 0;
    int start = 0, ansStart = -1, ansEnd = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (sum == 0) {
        start = i;
      }
      sum += nums[i];
      if (sum > maxi) {
        maxi = sum;
        ansStart = start;
        ansEnd = i;
      }
      if (sum < 0) {
        sum = 0;
      }
    }
    return vector<int>(nums.begin()+ansStart, nums.begin()+ansEnd+1);
  }
};

int main() {
  vector<int> nums = {2, 3, 5, -2, 7, -4}; // Output : 15
  Solution sl;
  cout << sl.maxSubarrSum(nums) << endl;
  for (int e : sl.maxSubarrSumEle(nums)) {
    cout << e << " ";
  }
  return 0;
}