/* Count number of nice subarrays
Given an array nums and an integer k. An array is called nice if and only if it contains k odd numbers. Find the number of nice subarrays in the given array nums. A subarray is continuous part of the array.

Examples

Input :nums = [1, 1, 2, 1, 1] , k = 3
Output :2
Explanation :The subarrays with three odd numbers are [1, 1, 2, 1] [1, 2, 1, 1]

Input : nums = [4, 8, 2] , k = 1
Output :0
Explanation :The array does not contain any odd number.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int niceArr(vector<int> &nums, int k){
    int countOdd = 0;
    for (int i = 0; i < nums.size(); i++){
      int sum = 0;
      for(int j = i; j < nums.size(); j++){
        if(nums[j] % 2 != 0) sum++;
        if(sum == k){
          countOdd++;
        } else if(sum > k){
          break;
        }
      }
    }
    return countOdd;
  }
  int niceArrSW(vector<int> &nums, int k){
    if(k < 0) return 0;
    int countOdd = 0, left = 0, sum = 0;
    for (int right = 0; right < nums.size(); right++){
      if(nums[right] % 2 != 0) sum++;
      while(sum > k){
        if(nums[left] % 2 != 0) sum--;
        left++;
      }
      countOdd += right - left + 1;
    }
    return countOdd;
  }
};

int main() {
  Solution sl;
  vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
  int k = 2;
  // Output :2
  cout<<sl.niceArr(nums, k)<<endl;
  cout<<sl.niceArrSW(nums, k) - sl.niceArrSW(nums, k-1)<<endl;
  return 0;
}
