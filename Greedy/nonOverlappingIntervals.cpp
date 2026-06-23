/* Non-overlapping Intervals
Given an array of N intervals in the form of (start[i], end[i]), where start[i] is the starting point of the interval and end[i] is the ending point of the interval, return the minimum number of intervals that need to be removed to make the remaining intervals non-overlapping. .

Examples

Input: Intervals = [ [1, 2], [2, 3], [3, 4], [1, 3] ]  
Output: 1  
Explanation: You can remove the interval [1, 3] to make the remaining intervals non-overlapping.

Input: Intervals = [ [1, 3], [1, 4], [3, 5], [3, 4], [4, 5] ]  
Output: 2  
Explanation: You can remove the intervals [1, 4] and [3, 5] to make the rest non-overlapping.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[1] < b[1];
    });
    int count = 0;
    int prev_end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] < prev_end) {
        count++;
      } else {
        prev_end = intervals[i][1];
      }
    }
    return count;
  }
};


int main() {
  // vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}}; // Output: 1 
  vector<vector<int>> intervals = {{1, 3}, {1, 4}, {3, 5}, {3, 4}, {4, 5}}; // Output: 2 
  Solution sl;
  cout<<sl.eraseOverlapIntervals(intervals)<<endl;
  return 0;
}
