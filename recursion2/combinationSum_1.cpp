/* Combination Sum - 1
Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Examples
 Example 1:
Input: array = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
             7 is a candidate, and 7 = 7.
             These are the only two combinations.

Example 2:
Input: array = [2], target = 1
Output: []
Explaination: No combination is possible.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
  void helper(int i, int target, vector<int>& temp, vector<int>& array, vector<vector<int>>& ans){
    
    if (target == 0) {
      ans.push_back(temp);
      return;
    }
    
    if (i == array.size() || target < 0) {
      return;
    }
    if (array[i] <= target) {
      temp.push_back(array[i]);
      helper(i, target - array[i], temp, array, ans); 
      temp.pop_back(); // Backtrack
    }
    helper(i + 1, target, temp, array, ans);
  }
  
public:
  vector<vector<int>> combinationalSum(int target, vector<int>& array){
    vector<vector<int>> ans;
    vector<int> temp;
    helper(0, target, temp, array, ans);
    return ans;
  }
};

int main() {
  vector<int> array = {2,3,6,7};
  int target = 7; // Output: [[2,2,3],[7]]

  Solution sl;
  sl.combinationalSum(target, array);
  vector<vector<int>> a = sl.combinationalSum(target, array);
  cout<<"ans array\n";
  for(auto it: a) {
    for(auto e: it) {
      cout<<e<<" ";
    }
    cout<<endl;
  }
  return 0;
}






