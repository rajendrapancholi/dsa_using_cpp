/* Printing Longest Increasing Subsequence
Put your HTML text here
Problem Description: Given an array of n integers arr, return the Longest Increasing Subsequence (LIS) that is index-wise lexicographically smallest.

The Longest Increasing Subsequence (LIS) is the longest subsequence where all elements are in strictly increasing order. A subsequence A1 is index-wise lexicographically smaller than another subsequence A2 if, at the first position where A1 and A2 differ, the element in A1 appears earlier in the array than corresponding element in A2.

Examples
Input: arr = [10, 22, 9, 33, 21, 50, 41, 60, 80]
Output: [10, 22, 33, 50, 60, 80]
Explanation: The LIS is [10, 22, 33, 50, 60, 80] and it is the lexicographically smallest.
Input: arr = [1, 3, 2, 4, 6, 5]
Output: [1, 3, 4, 6] 
Explanation: Possible LIS sequences are [1, 3, 4, 6] and [1, 2, 4, 6]. Since [1, 3, 4, 6] is index-wise lexicographically smaller, it is the result.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> LIS(vector<int> &nums){
    int n = nums.size();
    if( n == 0) return {};

    vector<int> temp;
    temp.push_back(nums[0]);

    for(int i = 1; i < n; i++){
      if(nums[i] > temp.back()) 
        temp.push_back(nums[i]);
      else {
        int idx = lower_bound(temp.begin(), temp.end(), temp.back()) - temp.begin();
        temp[idx] = nums[i];
      }
    }
    return temp;
  }
};

int main() {
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  Solution sl;

  for(auto el: sl.LIS(nums)){
    cout<<el<< ' ';
  }
  return 0;
}