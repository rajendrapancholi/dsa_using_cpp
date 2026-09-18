/* Prefix to Infix
Examples
Example 1:
Input:
-+a*b^-^cde+f*ghi
Output:
a + b * (c^d - e) ^ (f + g * h) - i

Example 2:
Input:
*+pq-mn
Output:
(p + q) * (m - n)
*/

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
  string prefix2infix(string str) { // TC = O(n), SC = O(n);
    if (str.size() == 0 || isOperand(str[0]))
      return "";

    reverse(str.begin(), str.end());

    stack<string> st;

    for (char c : str) {
      if (c == ' ')
        continue;
      else if (isOperand(c)) {
        st.push({c});
      } else {
        if (!st.empty()) {
          string t1 = st.top();
          st.pop();
          string t2 = st.top();
          st.pop();
          st.push({'(' + t1 + c + t2 + ')'});
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

  string str = "-+a*b^-^cde+f*ghi"; // a+b*(c^d-e)^(f+g*h)-i
  str = "*+pq-mn";                  // (p + q) * (m - n)

  Solution sl;
  auto result = sl.prefix2infix(str);
  cout << result << "\n";

  return 0;
}