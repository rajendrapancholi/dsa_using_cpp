/* Majority Elements(>N/3 times) | Find the elements that appears more than N/3
times in the array Given an integer array nums of size n. Return all elements
which appear more than n/3 times in the array. The output can be returned in any
order.

Examples
Example 1:
Input:
 nums = [1, 2, 1, 1, 3, 2]
Output:
 [1]
Explanation:
 Here, n / 3 = 6 / 3 = 2.
Therefore, the elements appearing 3 or more times are: [1].

Example 2:
Input:
 nums = [1, 2, 1, 1, 3, 2, 2]
Output:
 [1, 2]
Explanation:
 Here, n / 3 = 7 / 3 = 2.
Therefore, the elements appearing 3 or more times are: [1, 2]. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> majorityEle(vector<int> &nums) { // tc = O(n), sc = O(n)
    unordered_map<int, int> freq;
    vector<int> res;
    for (auto n : nums) {
      freq[n]++;
      if (freq[n] == nums.size() / 3 + 1) {
        res.push_back(n);
      }
      if (res.size() == 2)
        break;
    }
    sort(res.begin(), res.end());
    return res;
  }
  vector<int> majorityElementTwo(vector<int> &nums) { // tc = O(n), sc = O(1)
    int n = nums.size();
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;

    /*Find the potential candidates using
    Boyer Moore's Voting Algorithm*/
    for (int i = 0; i < n; i++) {

      if (cnt1 == 0 && el2 != nums[i])
        cnt1 = 1, el1 = nums[i];
      else if (cnt2 == 0 && el1 != nums[i])
        cnt2 = 1, el2 = nums[i];
      else if (nums[i] == el1)
        cnt1++;
      else if (nums[i] == el2)
        cnt2++;
      else
        cnt1--, cnt2--;
    }
    cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] == el1) {
        cnt1++;
      }
      if (nums[i] == el2) {
        cnt2++;
      }
    }
    int mini = n / 3 + 1;
    vector<int> result;
    if (cnt1 >= mini) {
      result.push_back(el1);
    }
    if (cnt2 >= mini && el1 != el2) {
      result.push_back(el2);
    }
    sort(result.begin(), result.end()); // TC O(2*log2) ~ O(1);
    return result;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> nums = {1, 2, 1, 1, 3, 2}; // 1
  nums = {1, 2, 1, 1, 3, 2, 2};          // 2 1
  Solution sl;
  auto result = sl.majorityEle(nums);
  auto result2 = sl.majorityElementTwo(nums);

  for (auto r : result) {
    cout << r << " ";
  }
  cout << "\n\n";
  for (auto r : result2) {
    cout << r << " ";
  }

  return 0;
}