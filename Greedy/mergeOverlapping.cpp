/* Merge Overlapping Sub-intervals
Given an array of intervals where intervals{i} = {starti, endi}, merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.

Examples
Input : intervals={1,3},{2,6},{8,10},{15,18}
Output : {1,6},{8,10},{15,18}
Explanation : Since intervals {1,3} and {2,6} are overlapping we can merge them to form {1,6} intervals.
Input : {1,4},{4,5}
Output :  {1,5}
Explanation :  Since intervals {1,4} and {4,5} are overlapping we can merge them to form {1,5}.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    for (auto interval : intervals) {
      if (res.empty() || res.back()[1] < interval[0]) {
        res.push_back(interval);
      } else {
        res.back()[1] = max(res.back()[1], interval[1]);
      }
    }
    return res;
  }
};

int main() {
  vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}}; // Output : {1,6},{8,10},{15,18}
  // vector<vector<int>> intervals = {{1,3},{4,6},{8,10},{15,18}}; // Output : {1,6},{8,10},{15,18}
  // vector<vector<int>> intervals = {{1,4},{4,5}}; // Output : {1,6},{8,10},{15,18}

  Solution sl;
  vector<vector<int>> ans = sl.mergeIntervals(intervals);
  for(auto el: ans){
    cout<<"["<<el[0]<<", "<<el[1]<<"]"<<", ";
  }

  return 0;
}
