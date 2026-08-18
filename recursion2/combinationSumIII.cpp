/* Combination Sum III
Determine all possible set of k numbers that can be added together to equal n while meeting the following requirements:
1. There is only use of numerals 1 through 9.
2. A single use is made of each number.
Return list of every feasible combination that is allowed. The combinations can be returned in any order, but the list cannot have the same combination twice.

Examples
Example 1:
Input:
 k = 3, n = 7
Output:
 [[1, 2, 4]]
Explanation:

1 + 2 + 4 = 7
There are no other valid combinations.

Example 2:
Input:
 k = 3, n = 9
Output:
 [[1, 2, 6],[1, 3, 5],[2, 3, 4]]
Explanation:

1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
*/

#include <iostream>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

class Solution {
private:
  void func(int sum, int last, vector<int> &nums, int k, vector<vector<int>> &ans) {
    if (sum == 0 && nums.size() == k) {
      ans.push_back(nums);
      return;
    }
    if (sum <= 0 || nums.size() > k)
      return;

    for (int i = last; i <= 9; i++) {
      if (i <= sum) {
        nums.push_back(i);
        func(sum - i, i + 1, nums, k, ans);
        nums.pop_back();
      }
      else {
        break;
      }
    }
  }

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> nums;
    func(n, 1, nums, k, ans);
    return ans;
  }
};

int main() {
  Solution sol;
  int k = 3;
  int n = 7;
  vector<vector<int>> result = sol.combinationSum3(k, n);

  for (const auto &combination : result) {
    for (int num : combination) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}
