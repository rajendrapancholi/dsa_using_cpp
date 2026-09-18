/* Postfix to prefix
Examples
Example 1:
Input:
Input: abcd^e-fgh*+^*+i
Output:
-+a*b^-^cde+f*ghi

Example 2:
Input: pq+mn-*
Output:
*+pq-mn */

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
  string postfix2prefix(string str) { // TC = O(n), SC = O(n);
    if (str.size() == 0 || !isOperand(str[0]))
      return "";
    stack<string> st;
    string ans = "";

    for (char c: str) {
      if (c == ' ')
        continue;
      else if (isOperand(c)){
        st.push({c});
      }
      else {
        if(st.size() >= 2){
          string t1 = st.top(); st.pop();
          string t2 = st.top(); st.pop();
          st.push({c + t2 + t1});
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

  string str = "abcd^e-fgh*+^*+i-"; //-+a*b^-^cde+f*ghi
  // str = "pq+mn-*";                 // *+pq-mn

  Solution sl;
  auto result = sl.postfix2prefix(str);
  cout << result << "\n";

  return 0;
}