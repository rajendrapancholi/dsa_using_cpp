/* Merge Overlapping Sub-intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all
overlapping intervals and return an array of the non-overlapping intervals that
cover all the intervals in the input.

Examples
Input : intervals=[[1,3],[2,6],[8,10],[15,18]]
Output : [[1,6],[8,10],[15,18]]
Explanation : Since intervals [1,3] and [2,6] are overlapping we can merge them
to form [1,6] intervals. Input : [[1,4],[4,5]] Output :  [[1,5]] Explanation :
Since intervals [1,4] and [4,5] are overlapping we can merge them to form [1,5].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> mergeOverlappingSubIntervalsM1(
      vector<vector<int>>
          &intervals) { // tc O(n^1), sc O(n) ~ sc O(1)(because only res is
                        // usage for storing the ans)
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;
    for (int i = 0; i < n;) {
      int start = intervals[i][0];
      int end = intervals[i][1];

      int j = i + 1;
      while (j < n && intervals[j][0] <= end) {
        end = max(end, intervals[j][1]);
        j++;
      }
      res.push_back({start, end});
      i = j;
    }

    return res;
  }

  vector<vector<int>> mergeOverlappingSubIntervalsM2(
      vector<vector<int>>
          &intervals) { // tc O(n^1), sc O(n) ~ sc O(1)(because only res is
                        // usage for storing the ans)
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for (int i = 1; i < n; i++) {
      int start = intervals[i][0];
      int end = intervals[i][1];
      if (start <= res.back()[1]) {
        if (res.back()[1] < end) {
          res.back()[1] = end;
        } else
          continue;
      } else {
        res.push_back(intervals[i]);
      }
    }

    return res;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<vector<int>> intervals = {{1, 3}, {2, 3}, {8, 10}, {15, 18}};
  Solution sl;
  auto result = sl.mergeOverlappingSubIntervalsM2(intervals);

  for (auto r : result) {
    for (auto e : r) {
      cout << e << " ";
    }
    cout << "\n";
  }

  return 0;
}