/* Reverse a stack using recursion
You are given a stack of integers. Your task is to reverse the stack using recursion. You may only use standard stack operations (push, pop, top/peek, isEmpty). You are not allowed to use any loop constructs or additional data structures like arrays or queues.

Your solution must modify the input stack in-place to reverse the order of its elements.

Examples
Example 1:
Input:
 stack = [4, 1, 3, 2]  
Output:
 [2, 3, 1, 4]

Example 2:
Input:
 stack = [10, 20, -5, 7, 15]
Output:
 [15, 7, -5, 20, 10]
*/
 
#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void insertAtBottom(stack<int> &st, int val) {
    if (st.empty()) {
      st.push(val);
      return;
    }
    int topVal = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(topVal);
  }

  void reverseStk(stack<int> &st) {
    if (st.empty()) return;
    int topVal = st.top();
    st.pop();
    reverseStk(st);
    insertAtBottom(st, topVal);
  }
};

int main() {
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(-5);
  st.push(7);
  st.push(15);

  Solution sl;
  while(!st.empty()){
    int v = st.top();
    st.pop();
    cout<<v<<' ';
  } cout<<endl;

  return 0;
}