/* Count the number of subarrays with given xor K
 Given an array of integers A and an integer B. Find the total number of
subarrays having bitwise XOR of all elements equal to k.

Examples
Input: A = [4, 2, 2, 6, 4] , k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2,
2, 6, 4], [2, 2, 6], [6] Input: A = [5, 6, 7, 8, 9], k = 5 Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6,
7, 8, 9] */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countSubArrXORKM1(vector<int> &nums, int k) { // tc = O(n^2), sc = O(1)
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      int xorVal = 0;
      for (int j = i; j < nums.size(); j++) {
        xorVal ^= nums[j];
        if (xorVal == k) {
          count++;
        }
      }
    }
    return count;
  }
  int countSubArrXORKM2(vector<int> &nums, int k) { // tc, sc = O(n)
    unordered_map<int, int> freq;
    freq[0] = 1;
    int prefixXor = 0;
    int count = 0;
    for (int num : nums) {
      prefixXor ^= num;
      int target = prefixXor ^ k;
      if (freq.find(target) != freq.end()) {
        count += freq[target];
      }
      freq[prefixXor]++;
    }
    return count;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  vector<int> nums = {4, 2, 2, 6, 4}; // Result: 4
  int k = 6;
  Solution sl;
  auto result = sl.countSubArrXORKM2(nums, k);

  cout << result << "\n";

  return 0;
}