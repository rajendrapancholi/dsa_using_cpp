/* Dynamic Programming: Ninja's Training
Problem Statement: .
Examples
Example 1:
Input: matrix = [[10, 40, 70], [20, 50, 80], [30, 60, 90]]
Output: 210
Explanation:
Day 1: fighting practice = 70
Day 2: stealth training = 50
Day 3: fighting practice = 90
Total = 70 + 50 + 90 = 210
This gives the optimal points.
Example 2:
Input: matrix = [[70, 40, 10], [180, 20, 5], [200, 60, 30]]
Output: 290 
Explanation:
Day 1: running = 70
Day 2: stealth training = 20
Day 3: running = 200
Total = 70 + 20 + 200 = 290
This gives the optimal points.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  // Memoization
  int helper(int day, int last, vector<vector<int>>&points, vector<vector<int>>& dp){
    if(dp[day][last] != -1) return dp[day][last];

    if(day == 0){ // base case
      int maxi = 0;
      for(int i = 0; i < 3; i++){
        if(i != last){
          maxi = max(maxi, points[0][i]);
        }
      }
      return dp[day][last] = maxi;
    }

    int maxi = 0;
    for(int i = 0; i < 3; i++){
      if(i!=last){
        int temp = points[day][i] + helper(day - 1, i, points, dp);
        maxi = max(maxi, temp);
      }
    }
    return dp[day][last] = maxi;
  }

public:
  int ninjasTranig(vector<vector<int>>&points){
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));

    return helper(n-1, 3, points, dp);
  }

  // Tabulation
  int ninjasTranig2(vector<vector<int>> &points){
    int n = points.size();
    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day = 1; day < n; day++){
      vector<int> temp(4, 0);
      for(int last = 0; last < 4; last++){
        temp[last] = 0;
        for(int curTask = 0; curTask < 3; curTask++){
          if(curTask != last){
            temp[last] = max(temp[last], points[day][curTask] + prev[curTask]);
          }
        }
      }
      prev = temp;
    }
    return prev[3];
  }

  // Space optimization
  int ninjasTranig3(vector<vector<int>>&points){
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));

    return helper(n-1, 3, points, dp);
  }
};


int main() {
  vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}}; // Output: 210
  Solution sl;
  cout<<sl.ninjasTranig(points)<<endl;
  cout<<sl.ninjasTranig2(points)<<endl;
  cout<<sl.ninjasTranig3(points)<<endl;
  return 0;
}
