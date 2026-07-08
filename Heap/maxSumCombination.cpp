/* Maximum Sum Combination
Given two integer arrays nums1 and nums2 and an integer k, return the maximum k valid sum combinations from all possible sum combinations using the elements of nums1 and nums2. A valid sum combination is made by adding one element from nums1 and one element from nums2. Return the answer in non-increasing order.

Examples
 Input : nums1 = [7, 3], nums2 = [1, 6], k = 2
 Output : [13, 9]
 Explanation : The 2 maximum combinations are made by: nums1[0] + nums2[1] = 13, nums1[1] + nums2[1] = 9 

 Input : nums1 = [3, 4, 5], nums2 = [2, 6, 3], k = 2 
 Output : [11, 10] 
 Explanation : The 2 maximum combinations are made by: nums1[2] + nums2[1] = 11 nums1[1] + nums2[1] = 10 
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> maxCombinations(vector<int>& nums1, vector<int>& nums2, int k) {
    sort(nums1.begin(), nums1.end(), greater<int>());
    sort(nums2.begin(), nums2.end(), greater<int>());
    priority_queue<tuple<int, int, int>> maxHeap;
    set<pair<int, int>> visited;
    maxHeap.push({nums1[0] + nums2[0], 0, 0});
    visited.insert({0, 0});
    vector<int> result;
    while(k-- && !maxHeap.empty()) {
      auto [sum, i, j] = maxHeap.top();
      maxHeap.pop();
      result.push_back(sum);
      if(i + 1 < nums1.size() && !visited.count({i + 1, j})) {
        maxHeap.push({nums1[i + 1] + nums2[j], i + 1, j});
        visited.insert({i + 1, j});
      }
      if(j + 1 < nums2.size() && !visited.count({i, j + 1})) {
        maxHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
        visited.insert({i, j + 1});
      }
    }
    return result;
  }
};

int main() {
  Solution sl;
  vector<int> nums1 = {7, 3};
  vector<int> nums2 = {1, 6};
  int k = 2;
  vector<int> result = sl.maxCombinations(nums1, nums2, k);
  for(int val : result) cout << val << " ";
  return 0;
}