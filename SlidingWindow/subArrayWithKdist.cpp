/* Subarray with k different integers
You are given an integer array nums and an integer k. Return the number of good subarrays of nums.

A good subarray is defined as a contiguous subarray of nums that contains exactly k distinct integers. A subarray is a contiguous part of the array.

Examples
Input: nums = [1, 2, 1, 2, 3], k = 2
Output: 7
Explanation: The 7 subarrays with exactly 2 different integers are:
[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Input: nums = [1, 2, 1, 3, 4], k = 3  
Output: 3
Explanation: The 3 subarrays with exactly 3 different integers are:  
[1,2,1,3], [2,1,3], [1,3,4]
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int subArrWithKdistintInt(vector<int> &nums, int k){
    int maxArrLen = 0, n = nums.size();
    for(int i = 0; i < n; i++){
      unordered_map<int, int> mp;
      for(int j = i; j < n; j++){
        mp[nums[j]]++;
        if(mp.size() == k){
          maxArrLen++;
        } else if(mp.size() > k) break;
      }
    }
    return maxArrLen;
  }

  int subArrWithKdistintIntSW(vector<int> &nums, int k){
    int count = 0, left = 0, n = nums.size();
    unordered_map<int, int> freq;

    for(int right = 0; right < n; right++){
      if(freq[nums[right]] == 0) k--;
      freq[nums[right]]++;
      while(k < 0){
        freq[nums[left]]--;
        if(freq[nums[left]] == 0) k++;
        left++;
      }
      count += right - left + 1;
    }
    return count;
  }
};

int main() {
  // vector<int> nums = {1, 2, 1, 2, 3};
  // int k = 2;
  // Output: 7
  vector<int> nums = {1, 2, 1, 3, 4};
  int k = 3 ;
  Solution sl;
  cout<<sl.subArrWithKdistintInt(nums, k)<<endl;
  cout<<sl.subArrWithKdistintIntSW(nums, k) - sl.subArrWithKdistintIntSW(nums, k-1)<<endl;
  return 0;
}
