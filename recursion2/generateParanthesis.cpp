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
  // optimize
  void optGenValidParanthesis(int open, int close, string crr, int n, vector<string>& ans){
    if(crr.length() == 2 * n){
      ans.push_back(crr);
      return;
    }
    if(open < n) optGenValidParanthesis(open + 1, close, crr + '(', n, ans);
    if(close < open) optGenValidParanthesis(open, close + 1, crr + ')', n, ans);    
  }
};

int main() {
  Solution sl;
  int n = 10;
  vector<string> ans;
  clock_t start_bf = clock();
  sl.genValidParanthesis("", n, ans);
  clock_t end_bf = clock();
  double time_bf = ((double)(end_bf - start_bf) / CLOCKS_PER_SEC) * 1000;
  cout << "Brute Force:" << endl;
  for(auto it: ans) {
      cout << it << endl;
  }
  cout << "BF" << time_bf << " ms" << endl << endl;

  ans = {};
  clock_t start_of = clock();
  sl.optGenValidParanthesis(0, 0, "", n, ans);
  clock_t end_of = clock();
  double time_of = ((double)(end_of - start_of) / CLOCKS_PER_SEC) * 1000;
  cout<<"Optimize:"<<endl;
  for(auto it: ans) {
    cout<<it<<endl;
  }
  cout << "OF: " << time_of << " ms" << endl << endl;
  return 0;
}
