/* Maximum Nesting Depth of Parenthesis
Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

Examples
Example 1:
Input:
 s = "(1+(2*3)+((8)/4))+1"
Output:
 3
Explanation:
 Digit 8 is inside of 3 nested parentheses in the string.

Example 2:
Input:
 s = "(1)+((2))+(((3)))"
Output:
 3
Explanation:
 Digit 3 is inside of 3 nested parentheses in the string.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findMaxParDepth(string s){
    int n = s.size(), mxDepth = 0, count = 0;
    vector<char> st;
    for(int i = 0; i < n; i++){
      if(s[i] == '(') st.push_back('(');
      else if(s[i] == ')'){
        st.pop_back();
        if(st.empty()){
          mxDepth = max(mxDepth, count);
          count = 0;
        }
        count++;
      }
    }
    return st.empty() ? mxDepth : -1;
  }

  int findMaxParDepth2(string s) {
    int p = 0;  
    int ans = 0;
    for (char x : s) {
        if (x == '(') p++;
        else if (x == ')') p--;
        ans = max(ans, p);
    }
    return ans;
  }
};

int main() {
  // string s = "(1+(2*3)+((8)/4))+1"; // Output: 3
  string  s = "(1)+((2))+(((3)))"; // Output: 3
  Solution sl;
  cout<<sl.findMaxParDepth(s)<<endl;
  cout<<sl.findMaxParDepth2(s)<<endl;
  return 0;
}
