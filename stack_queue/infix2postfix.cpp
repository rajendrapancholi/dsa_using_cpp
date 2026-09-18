/* Infix to Postfix
Given an infix expression, Your task is to convert the given infix expression to
a postfix expression.

Examples
Example 1:
Input:
 a + b * (c^d - e) ^ (f + g * h) - i
Output:
 abcd^e-fgh*+^*+i-
Explanation:

The infix expression "a + b * (c^d - e) ^ (f + g * h) - i" is converted to
postfix form as "abcd^e-fgh*+^*+i-" by applying the rules of infix to postfix
conversion.

Example 2:
Input:
 (p + q) * (m - n)
Output:
 pq+mn-*
Explanation:

The infix expression "(p + q) * (m - n)" is converted to postfix form as
"pq+mn-*". */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  int precedence(char ch) {
    switch (ch) {
    case '^':
      return 3;
    case '*':
    case '/':
    case '%':
      return 2;
    case '+':
    case '-':
      return 1;
    default:
      return 0;
    }
  }
  bool isOperand(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'))
               ? true
               : false;
  }

public:
  string infix2postfix(string str) { // TC = O(n), SC = O(n);
    if (str.size() == 0)
      return "";
    string ans = "";
    stack<char> st;
    for (char c : str) {
      if(c == ' ') continue;
      else if (isOperand(c))
        ans += c;
      else if (c == '(')
        st.push(c);
      else if (c == ')') {
        while (!st.empty() && st.top() != '(') {
          ans += st.top();
          st.pop();
        }
        if (!st.empty()) st.pop(); // remove '('
      } else {
        while (!st.empty() && precedence(c) <= precedence(st.top())) {
          ans += st.top();
          st.pop();
        }
        st.push(c);
      }
    }
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }
    return ans;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str = "a + b * (c^d - e) ^ (f + g * h) - i"; // abcd^e-fgh*+^*+i-
  Solution sl;
  auto result = sl.infix2postfix(str);
  cout << result << "\n";

  return 0;
}