/* Longest Subarray with given Sum K(Positives)
an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

Examples
Example 1:
Input:
 nums = [10, 5, 2, 7, 1, 9], k = 15  
Output:
 4  
Explanation:
 The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.

Example 2:
Input:
 nums = [-3, 2, 1], k = 6  
Output:
 0  
Explanation:
 There is no sub-array in the array that sums to 6. Therefore, the output is 0.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int msa(vector<int>& nums, int k){
    int n = nums.size(), mx = 0;
    int i = 0, j = 0, sm = nums[0];
    while(j < n){
      while(i <= j && sm > k){
        sm -= nums[i];
        i++;
      }
      if(sm == k) mx = max(mx, j-i+1);
      j++;
      if(j<n) sm += nums[j];
    }
    return mx;
  }
};

int main() {
  vector<int>  nums = {11, 5, 2, 7, 1, 9}; int k = 15;
  // vector<int>  nums = {-3, 2, 1}; int k = 6;
  Solution sl;
  cout<<sl.msa(nums, k)<<endl;
  
  return 0;
}