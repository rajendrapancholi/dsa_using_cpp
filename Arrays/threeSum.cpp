/* 3 Sum : Find triplets that add up to a zero
Given an array of N integers, your task is to find unique triplets that add up
to give a sum of zero. In short, you need to return an array of all the unique
triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is
equal to zero.

Examples
Example 1:
Input:
 nums = [-1,0,1,2,-1,-4]
Output:
 [[-1,-1,2],[-1,0,1]]
Explanation:
 Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] satisfy
the condition of summing up to zero with i!=j!=k


Example 2:
Input:
 nums=[-1,0,1,0]
Output:
 Output: [[-1,0,1],[-1,1,0]]
Explanation:
 Out of all possible unique triplets possible, [-1,0,1] and [-1,1,0] satisfy the
condition of summing up to zero with i!=j!=k */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // TC => O(N^3 * log(no. of unique triplets)),
  // SC => O(2 * no. of the unique triplets)
  vector<vector<int>> threeSumM1(vector<int> &nums) {
    int n = nums.size();
    set<vector<int>> res;
    for (int i = 0; i < n - 1; i++) {
      set<int> tempset;
      for (int j = i + 1; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (nums[i] + nums[j] + nums[k] == 0) {
            vector<int> temp = {nums[i], nums[j], nums[k]};
            sort(temp.begin(), temp.end());
            res.insert(temp);
          }
        }
      }
    }
    return vector<vector<int>>(res.begin(), res.end());
  }
  // TC => O(N^2 * log(no. of unique triplets)),
  // SC => O(2* no. of the unique triplets) + O(N)
  vector<vector<int>> threeSumM2(vector<int> &nums) {
    int n = nums.size();
    set<vector<int>> res;
    for (int i = 0; i < n - 1; i++) {
      set<int> tempset;
      for (int j = i + 1; j < n; j++) {
        int third = -(nums[i] + nums[j]);
        if (tempset.find(third) != tempset.end()) {
          vector<int> temp = {nums[i], nums[j], third};
          sort(temp.begin(), temp.end());
          res.insert(temp);
        }
        tempset.insert(nums[j]);
      }
    }
    return vector<vector<int>>(res.begin(), res.end());
  }

  // TC => O(NlogN)+O(N^2),
  // SC => O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).
  vector<vector<int>> threeSumM3(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;  
    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int left = i + 1, right = n - 1;
      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];

        if (sum == 0) {
          ans.push_back({nums[i], nums[left], nums[right]});
          left++, right--;

          while (left < right && nums[left] == nums[left - 1])
            left++;
          while (left < right && nums[right] == nums[right + 1])
            right--;
        } else if (sum < 0)
          left++;
        else
          right--;
      }
    }
    return ans;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> nums = {-1, 0, 1, 2, -1, -4}; // Output: [[-1,-1,2],[-1,0,1]]
  Solution sl;
  auto result = sl.threeSumM3(nums);

  for (auto r : result) {
    cout << "[ ";
    for (auto e : r) {
      cout << e << " ";
    }
    cout << "]\n";
  }

  return 0;
}
