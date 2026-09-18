/* Postfix to Infix
Given an postfix expression, Your task is to convert the given postfix expression to
a infix expression.

Examples
Example 1:
Input: abcd^e-fgh*+^*+i
Output: a+b*(c^d-e)^(f+g*h)-i

Explanation:
The infix expression "a + b * (c^d - e) ^ (f + g * h) - i" is converted to
postfix form as "abcd^e-fgh*+^*+i-" by applying the rules of infix to postfix
conversion.

Example 2:
Input: pq+mn-*
Output: (p + q) * (m - n)
Explanation:

The infix expression "(p + q) * (m - n)" is converted to postfix form as
"pq+mn-*" */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool isOperand(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'))
               ? true
               : false;
  }

public:
  string postfix2infix(string str) { // TC = O(n), SC = O(n);
    if (str.size() == 0)
      return "";
    string ans = "";
    stack<string> st;
    for (char c : str) {
      if(c == ' ') continue;
      else if (isOperand(c)){
        st.push({c});
      }
      else {
        if(!st.empty()){
          string t1 = st.top(); st.pop();
          string t2 = st.top(); st.pop();
          st.push({'('+t2 + c + t1 + ')'});
        }
      }
    }

    return st.top();
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str = "abcd^e-fgh*+^*+i-"; // a + b * (c^d - e) ^ (f + g * h) - i
  str = "pq+mn-*"; // a + b * (c^d - e) ^ (f + g * h) - i
  Solution sl;
  auto result = sl.postfix2infix(str);
  cout << result << "\n";

  return 0;
}