/* Job Sequencing Problem
You are given a set of N jobs where each job comes with a deadline and profit. The profit can only be earned upon completing the job within its deadline. Find the number of jobs done and the maximum profit that can be obtained. Each job takes a single unit of time and only one job can be performed at a time.

Examples
Example 1:
Input:
  
N = 4, Jobs = {(1, 4, 20), (2, 1, 10), (3, 1, 40), (4, 1, 30)}  
Output:
 2 60  
Explanation:
  
- The 3rd job with a deadline of 1 is performed during the first unit of time.  
- The 1st job is performed during the second unit of time as its deadline is 4.  
Profit = 40 + 20 = 60.  
So, the result is 2 jobs with a total profit of 60.

Example 2:
Input:
  
N = 5, Jobs = {(1, 2, 100), (2, 1, 19), (3, 2, 27), (4, 1, 25), (5, 1, 15)}  
Output:
 2 127  
Explanation:
  
The first and third jobs, both having a deadline of 2, give the highest profit.  
Profit = 100 + 27 = 127.  
So, the result is 2 jobs with a total profit of 127.
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct Job {
  int seq, dl, profit;
};

class Solution {
public:
  pair<int, int> jobScheculing(int n, Job arr[]){
    sort(arr, arr + n, [](Job a, Job b){
      return a.profit > b.profit;
    });

    int mxi = arr[0].dl, countJobs = 0, mxProfit = 0;
    for(int i = 1; i < n; i++){
      mxi = max(mxi, arr[i].dl);
    }

    int slot[mxi + 1];
    for (int i = 0; i <= mxi; i++)
      slot[i] = -1;

    for(int i = 0; i < n; i++){
      for(int j = arr[i].dl; j > 0; j--){
        if(slot[j] == -1){
          slot[j] = i;
          countJobs++;
          mxProfit += arr[i].profit;
          break;
        }
      }
    }

    return make_pair(countJobs, mxProfit);
  }
};

int main() {
  int n = 4;
  Job arr[n] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}}; // Output: 2 60
  Solution sl;
  pair<int, int> ans = sl.jobScheculing(n, arr);
  cout<<ans.first<<' '<<ans.second<<endl;
  return 0;
}