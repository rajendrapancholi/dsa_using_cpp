/* Minimum number of bracket reversals needed to make an expression balanced
Given a string s consisting of only opening and closing brackets '(' and ')', find out the minimum number of reversals required to convert the string into a balanced expression.

If it is not possible to make the brackets balanced, return -1. A reversal means changing '(' to ')' or vice-versa.

Examples
Input : s = ")(())((("
Output : 3
Explanation :  One way to balance is: "((())())". There is no balanced sequence that can be formed in lesser reversals.
Input : s = "(()((()(())(("
Output : -1
Explanation : There's no way we can balance this sequence of braces.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minNumBracket(string s) { // TC = O(n), SC = O(1);
    int n = s.size();
    if(n&1 == 1) return -1;
    int open = 0, close = 0;
    for (auto ch : s) {
      if(ch == '(') open++;
      else  {
        if(open > 0) open--;
        else close++;
      }
    }
    return (open+1)/2 + (close+1)/2;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s = ")(())((("; // Output : 3
  // s = "(()((()(())(("; // Output : -1
  Solution sl;
  auto result = sl.minNumBracket(s);
  cout << result << "\n";
  
  return 0;
}