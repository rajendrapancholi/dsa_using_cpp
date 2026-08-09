/* Sort a Stack
You are given a stack of integers. Your task is to sort the stack in descending order using recursion, such that the top of the stack contains the greatest element. You are not allowed to use any loop-based sorting methods (e.g., quicksort, mergesort). You may only use recursive operations and the standard stack operations (push, pop, peek/top, and isEmpty).

Examples
Example 1:
Input:
 stack = [4, 1, 3, 2]
Output:
 [4, 3, 2, 1]
Explanation:
 After sorting, the largest element (4) is at the top, and the smallest (1) is at the bottom.

Example 2:
Input:
 stack = [1]
Output:
 [1]
Explanation:
 A single-element stack is already sorted.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void insert(stack<int>& s, int temp) {
    if (s.empty() || s.top() <= temp) {
      s.push(temp);
      return;
    }
    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
  }
  void srtStack(stack<int>& s) {
    if (!s.empty()) {
      int temp = s.top();
      s.pop();
      srtStack(s);
      insert(s, temp);
    }
  }
};

int main() {
  Solution sl;
  stack<int> st;
  st.push(4);
  st.push(1);
  st.push(3);
  st.push(2);
  sl.srtStack(st);
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}
