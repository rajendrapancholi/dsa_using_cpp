/* Find the Majority Element that occurs more than N/2 times
Given an integer array nums of size n, return the majority element of the array.
The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.
Examples
Example 1:
Input:
 nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]  
Output: 7
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int majority(vector<int>& nums) {
    int n = nums.size();
    // unordered_map<int, int> map;
    // for(int n: nums){
    //   map[n]++;
    // }
    // for(int n: nums){
    //   if(map[n] >= n/2) return n;
    // }
    
    // Moore's Algorithm
    int count = 0, el = INT_MIN;
    for(int n: nums){
      if(count == 0) count = 1, el = n;
      else if(n == el) count++;
      else count--;
    }
    count = 0;
    for(int n: nums){
      if(n == el) count++;
    }
    return (count > n/2) ? el: -1;
  }
};

int main() {
  vector<int> nums = {2,2,1,1,1,2,2};
  Solution sl;
  cout<<sl.majority(nums)<<endl;
  return 0;
}
