/* Binary subarray with sum
You are given a binary array nums (containing only 0s and 1s) and an integer goal. Return the number of non-empty subarrays of nums that sum to goal. A subarray is a contiguous part of the array.

Examples
Input: nums = [1, 0, 0, 1, 1, 0], goal = 2  
Output: 6
Explanation: There are 6 subarrays with sum exactly equal to 2:
[1, 0, 0, 1], [0, 0, 1, 1], [0, 1, 1], [1, 1], [1, 1, 0], [0,0,1,1,0]


Input: nums = [0,0,0,0,0,0], goal = 0  
Output: 21  
Explanation: All subarrays with only 0s will have sum = 0.  
There are 21 such subarrays in total (n(n+1)/2 = 6*7/2 = 21).
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int binarySumArr(vector<int> &nums, int gl){
    int maxLen = 0;
    
    for(int i = 0; i < nums.size(); i++){
      int sum = 0;
      for(int j = i; j < nums.size(); j++){
        sum += nums[j];
        if(sum == gl) {
          maxLen++;
        } else if(sum > gl) 
          break;
      }
    }
    return maxLen;
  }

  int binarySumArrSW(vector<int> &nums, int gl){
    if (gl < 0) return 0;
    int count = 0, left = 0, sum = 0;
    for(int right = 0; right < nums.size(); right++){
      sum += nums[right];
      while(sum > gl) {
        sum -= nums[left];
        left++;
      }
      count += right - left + 1;
    }
    return count;
  }
};

int main() {
  vector<int>  nums = {1, 0, 0, 1, 1, 0};
  int goal = 2;
  Solution sl;
  cout<<sl.binarySumArr(nums, goal)<<endl;
  cout<<sl.binarySumArrSW(nums, goal) - sl.binarySumArrSW(nums, goal-1)<<endl;
  return 0;
}
