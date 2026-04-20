/* Target Sum
We are given an array ‘ARR’ of size ‘N’ and a number ‘Target’. Our task is to build an expression from the given array where we can place a ‘+’ or ‘-’ sign in front of an integer. We want to place a sign in front of every integer of the array and get our required target. We need to count the number of ways in which we can achieve our required target.

Examples
Input : nums = [1,1,1,1,1], target = 3
Output : 5
Explanation : There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Input : nums = [1], target = 1
Output : 1
Explanation : There is only one number, and we can assign a '+' sign to it to reach the target.
+1 = 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int total = accumulate(nums.begin(), nums.end(), 0);

    if ((total + target) % 2 != 0 || abs(target) > total)
      return 0;

    int newTarget = (total + target) / 2;

    vector<int> dp(newTarget + 1, 0);

    dp[0] = 1;

    for (int num : nums) {
      for (int j = newTarget; j >= num; j--) {
        dp[j] += dp[j - num];
      }
    }

    return dp[newTarget];
  }
};
int main() {
  Solution sol;
  vector<int> nums = {1, 1, 1, 1, 1};
  int target = 3;
  cout << sol.findTargetSumWays(nums, target) << endl;
  return 0;
}
