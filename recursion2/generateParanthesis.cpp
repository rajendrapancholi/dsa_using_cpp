/* Generate Paranthesis
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Examples
Example 1:
Input:
 n = 3
Output:
 ["((()))", "(()())", "(())()", "()(())", "()()()"]

Example 2:
Input:
 n = 1
Output:
 ["()"]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  bool isValid(string crr){
    int bal = 0;
    for(auto c: crr) {
      if(c == '(')bal++; else bal--; 
      if (bal < 0) return false;
    }
    return bal == 0;
  } 
public:
  void genValidParanthesis(string crr, int n, vector<string>& ans){
    if(crr.length() == 2 * n){
      if(isValid(crr)) ans.push_back(crr);
      return;
    }
    genValidParanthesis(crr + '(', n, ans);
    genValidParanthesis(crr + ')', n, ans);    
  }
};

int main() {
  Solution sl;
  int n = 3;
  vector<string> ans;
  sl.genValidParanthesis("", n, ans);
  
  for(auto it: ans) {
    cout<<it<<endl;
  }
  return 0;
}
