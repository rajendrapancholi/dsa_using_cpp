/* Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Examples:
  Input: nums = [1,1,1,2,2,3], k = 2
  Output: [1,2]

  Input: nums = [1], k = 1
  Output: [1]

  Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
  Output: [1,2]

Constraints:
  1 <= nums.length <= 105
  -104 <= nums[i] <= 104
  k is in the range [1, the number of unique elements in the array].
  It is guaranteed that the answer is unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  vector<int> largestFreqEle(vector<int> &nums, int k) {
    set<pair<int, int>> freq;
    for(int i = 0; i < nums.size(); i++){
      int f = count(nums.begin(), nums.end(), nums[i]);
      freq.insert({nums[i], f});
    }
    vector<pair<int, int>> temp;
    for(auto it: freq) {
      temp.push_back({it.first, it.second});
    }
    sort(temp.begin(), temp.end(), [](pair<int, int> a, pair<int, int> b){
      return a.second > b.second;
    });
    vector<int> ans;
    for(auto e: temp){
      ans.push_back(e.first);
      k--;
      if(k <= 0) break;
    }
    return ans;
  }
  vector<int> topKFrequent(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> counts;
    for (int num : nums) {
      counts[num]++;
    }
    
    vector<vector<int>> buckets(n + 1);
    for (auto& pair : counts) {
      int num = pair.first;
      int freq = pair.second;
      buckets[freq].push_back(num);
    }
    vector<int> result;
    for (int i = n; i >= 0; --i) {
      for (int num : buckets[i]) {
        result.push_back(num);
        if (result.size() == k) {
          return result;
        }
      }
    }
    return result;
  }
};

int main() {
  vector<int> nums = {11, 2, 1, 2, 1, 2, 3, 1, 3, 2}; int k = 2; // Output: [1,2]

  Solution sl;
  for(auto e: sl.topKFrequent(nums, k)){
    cout<<e<<' ';
  }
  return 0;
}
