/* Insert Interval
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<pair<int, int>> insertInterval(vector<pair<int, int>> &intervals, pair<int, int> newInterval){
    vector<pair<int, int>> res;
    int i = 0;
    int n = intervals.size();
    while (i < n && intervals[i].second < newInterval.first) {
      res.push_back(intervals[i]);
      i++;
    }
    while (i < n && intervals[i].first <= newInterval.second) {
      newInterval.first = min(newInterval.first, intervals[i].first);
      newInterval.second = max(newInterval.second, intervals[i].second);
      i++;
    }
    res.push_back(newInterval);
    
    while (i < n) {
      res.push_back(intervals[i]);
      i++;
    }
    return res;
  }
};

int main() {
  // vector<pair<int, int>> intervals = {{1, 3}, {6, 9}};
  // pair<int, int> newInterval = {2,5}; // Output: [[1,5], [6,9]]

  vector<pair<int, int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
  pair<int, int> newInterval = {4,8};

  Solution sl;
  vector<pair<int, int>> ans = sl.insertInterval(intervals, newInterval);
  return 0;
}
