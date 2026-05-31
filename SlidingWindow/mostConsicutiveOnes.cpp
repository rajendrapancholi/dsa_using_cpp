/* Max Consecutive Ones III
Problem Statement: Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Examples
Input : nums = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0] , k = 3
Output : 10
Explanation : The maximum number of consecutive 1's are obtained only if we flip the 0's present at position 3, 4, 5 (0 base indexing).
The array after flipping becomes [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0].
The number of consecutive 1's is 10.

Input : nums = [0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1] , k = 3
Output : 9
Explanation : The underlines 1's are obtained by flipping 0's in the new array.
[1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1].
The number of consecutive 1's is 9.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findMostConscutive1s(vector<int> &nums, int k){
    int n = nums.size();
    int maxLen = 0;
    for(int i = 0; i < n; i++){
      int zeros = 0;
      for(int j = i; j < n; j++){
        if(zeros > k) break;
        if(nums[j] == 0) zeros++;
        maxLen = max(maxLen, j - i + 1);
      }
    }
    return maxLen - 1;
  }
  int findMostConscutive1sSW(vector<int> &nums, int k){
    int n = nums.size();        
    int maxLen = 0, zeros = 0, l = 0;
    for (int r = 0; r < n; r++) {
      if (nums[r] == 0) {
        zeros++;
      }
      while (zeros > k) {
        if (nums[l] == 0) {
          zeros--;
        }
        l++;
      }
      int len = r - l + 1;
      maxLen = max(maxLen, len);
    }
    return maxLen;
  }
};

int main() {
  // vector<int> nums = {0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1};
  vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
  int k = 3;
  Solution sl;
  cout<<sl.findMostConscutive1s(nums, k)<<endl;
  cout<<sl.findMostConscutive1sSW(nums, k)<<endl;
  return 0;
}
