/* Remove Outermost Parentheses
A valid parentheses string is defined by the following rules:

It is the empty string "".
If A is a valid parentheses string, then so is "(" + A + ")".
If A and B are valid parentheses strings, then A + B is also valid.
A primitive valid parentheses string is a non-empty valid string that cannot be split into two or more non-empty valid parentheses strings.
Given a valid parentheses string s, your task is to remove the outermost parentheses from every primitive component of s and return the resulting string.

Examples
Example 1:
Input: s = "((()))"
Output:
 "(())"
Explanation:
 The input string is a single primitive: "((()))".  
Removing the outermost layer yields: "(())".

Example 2:
Input:
 s = "()(()())(())"
Output:
 "()()()"
Explanation:
 Primitive decomposition: "()" + "(()())" + "(())"  
After removing outermost parentheses: "" + "()()" + "()"
Final result: "()()()".
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
  string rmOuterMostPar(string &s){
    string ans = "";
    int level = 0;
    for(int i = 0; i < s.size(); i++){
      if(s[i] == '('){
        if(level > 0) ans += s[i];
        level++;
      } else if(s[i] == ')'){
        level--;
        if(level > 0) ans += s[i];
      }
    }
    return ans;
  }
};

int main() {
  string s = "()(()())(())";
  Solution sl;
  cout<<sl.rmOuterMostPar(s)<<endl;
  return 0;
}
