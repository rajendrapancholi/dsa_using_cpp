/* Task Scheduler
You are given a list of tasks represented by uppercase English letters ('A' to 'Z'), and an integer n representing a cooldown interval between two same tasks. Each task takes exactly 1 CPU interval to complete. Tasks can be executed in any order, but identical tasks must be separated by at least n intervals, during which the CPU may remain idle or execute other tasks.
Return the minimum number of CPU intervals required to complete all the tasks .

Examples
Input :  tasks = ["A","A","A","B","B","B"], n = 2
Output :  8
Explanation : One valid execution order is:
A -> B -> idle -> A -> B -> idle -> A -> B
Total intervals = 8

Input :  tasks = ["A","C","A","B","D","B"], n = 1
Output : 6
 Explanation A possible execution:
A -> B -> C -> D -> A -> B
No idle interval is needed as cooldown = 1.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int leastIntervals(vector<char> &tasks, int n){
    unordered_map<char, int> freq;
    for(auto t: tasks) freq[t]++;
    
    priority_queue<int> mxHeap;
    for(auto& it: freq) mxHeap.push(it.second);
    
    int t = 0;
    while(!mxHeap.empty()){
      vector<int> tmp;
      int cycle = n + 1, i = 0;
      while(i < cycle && !mxHeap.empty()){
        int ct = mxHeap.top();
        mxHeap.pop();
        ct--;
        if(ct > 0) tmp.push_back(ct);
        t++, i++;
      }
      for(auto it: tmp) mxHeap.push(it);
      if(mxHeap.empty()) break;
      t += (cycle - i);
    }
    return t;
  }
};

int main() {
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  int n = 2; // Output :  8
  
  Solution sl;
  cout<<sl.leastIntervals(tasks, n)<<endl;
  return 0;
}
